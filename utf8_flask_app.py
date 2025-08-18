
from flask import Flask, request, jsonify
from flask_cors import CORS
from flask_pymongo import PyMongo
from flask_jwt_extended import JWTManager, create_access_token, jwt_required, get_jwt_identity
from werkzeug.security import generate_password_hash, check_password_hash
from bson.objectid import ObjectId
import datetime

app = Flask(__name__)
CORS(app)

# MongoDB config (update URI as needed)
app.config["MONGO_URI"] = "mongodb://localhost:27017/commerce_db"
app.config["JWT_SECRET_KEY"] = "your_jwt_secret_key"  # Change this in production!
app.config["JWT_ACCESS_TOKEN_EXPIRES"] = datetime.timedelta(days=1)

mongo = PyMongo(app)
jwt = JWTManager(app)

def is_admin(user_id):
    user = mongo.db.users.find_one({"_id": ObjectId(user_id)})
    return user and user.get("is_admin", False)

@app.route('/')
def home():
    return {"message": "Backend is running!"}

@app.route('/api/auth/register', methods=['POST'])
def register():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    if not username or not password:
        return jsonify({"error": "Username and password required."}), 400
    if mongo.db.users.find_one({"username": username}):
        return jsonify({"error": "Username already exists."}), 409
    hashed_pw = generate_password_hash(password)
    mongo.db.users.insert_one({"username": username, "password": hashed_pw})
    return jsonify({"message": "User registered successfully."}), 201

@app.route('/api/auth/login', methods=['POST'])
def login():
    data = request.get_json()
    username = data.get('username')
    password = data.get('password')
    user = mongo.db.users.find_one({"username": username})
    if not user or not check_password_hash(user['password'], password):
        return jsonify({"error": "Invalid credentials."}), 401
    access_token = create_access_token(identity=str(user['_id']))
    return jsonify({"access_token": access_token}), 200

@app.route('/api/auth/me', methods=['GET'])
@jwt_required()
def me():
    user_id = get_jwt_identity()
    user = mongo.db.users.find_one({"_id": ObjectId(user_id)})
    if not user:
        return jsonify({"error": "User not found."}), 404
    return jsonify({"username": user['username']}), 200

@app.route('/api/products', methods=['POST'])
@jwt_required()
def create_product():
    data = request.get_json()
    name = data.get('name')
    price = data.get('price')
    description = data.get('description', '')
    if not name or price is None:
        return jsonify({"error": "Name and price are required."}), 400
    product = {
        "name": name,
        "price": price,
        "description": description
    }
    result = mongo.db.products.insert_one(product)
    product['_id'] = str(result.inserted_id)
    return jsonify(product), 201

@app.route('/api/products', methods=['GET'])
def get_products():
    products = []
    for prod in mongo.db.products.find():
        prod['_id'] = str(prod['_id'])
        products.append(prod)
    return jsonify(products), 200

@app.route('/api/products/<product_id>', methods=['GET'])
def get_product(product_id):
    prod = mongo.db.products.find_one({"_id": ObjectId(product_id)})
    if not prod:
        return jsonify({"error": "Product not found."}), 404
    prod['_id'] = str(prod['_id'])
    return jsonify(prod), 200

@app.route('/api/products/<product_id>', methods=['PUT'])
@jwt_required()
def update_product(product_id):
    data = request.get_json()
    update_data = {k: v for k, v in data.items() if k in ['name', 'price', 'description']}
    if not update_data:
        return jsonify({"error": "No valid fields to update."}), 400
    result = mongo.db.products.update_one({"_id": ObjectId(product_id)}, {"$set": update_data})
    if result.matched_count == 0:
        return jsonify({"error": "Product not found."}), 404
    prod = mongo.db.products.find_one({"_id": ObjectId(product_id)})
    prod['_id'] = str(prod['_id'])
    return jsonify(prod), 200

@app.route('/api/products/<product_id>', methods=['DELETE'])
@jwt_required()
def delete_product(product_id):
    result = mongo.db.products.delete_one({"_id": ObjectId(product_id)})
    if result.deleted_count == 0:
        return jsonify({"error": "Product not found."}), 404
    return jsonify({"message": "Product deleted."}), 200

@app.route('/api/cart', methods=['GET'])
@jwt_required()
def get_cart():
    user_id = get_jwt_identity()
    cart = mongo.db.carts.find_one({"user_id": user_id})
    if not cart:
        return jsonify({"items": []}), 200
    # Convert ObjectId to string for product_id
    for item in cart['items']:
        item['product_id'] = str(item['product_id'])
    return jsonify({"items": cart['items']}), 200

@app.route('/api/cart', methods=['POST'])
@jwt_required()
def add_to_cart():
    user_id = get_jwt_identity()
    data = request.get_json()
    product_id = data.get('product_id')
    quantity = data.get('quantity', 1)
    if not product_id:
        return jsonify({"error": "Product ID required."}), 400
    product = mongo.db.products.find_one({"_id": ObjectId(product_id)})
    if not product:
        return jsonify({"error": "Product not found."}), 404
    cart = mongo.db.carts.find_one({"user_id": user_id})
    if not cart:
        cart = {"user_id": user_id, "items": []}
    # Check if product already in cart
    for item in cart['items']:
        if str(item['product_id']) == product_id:
            item['quantity'] += quantity
            break
    else:
        cart['items'].append({"product_id": ObjectId(product_id), "quantity": quantity})
    mongo.db.carts.update_one({"user_id": user_id}, {"$set": {"items": cart['items']}}, upsert=True)
    return jsonify({"message": "Added to cart."}), 200

@app.route('/api/cart', methods=['PUT'])
@jwt_required()
def update_cart_item():
    user_id = get_jwt_identity()
    data = request.get_json()
    product_id = data.get('product_id')
    quantity = data.get('quantity')
    if not product_id or quantity is None:
        return jsonify({"error": "Product ID and quantity required."}), 400
    cart = mongo.db.carts.find_one({"user_id": user_id})
    if not cart:
        return jsonify({"error": "Cart not found."}), 404
    for item in cart['items']:
        if str(item['product_id']) == product_id:
            item['quantity'] = quantity
            break
    else:
        return jsonify({"error": "Product not in cart."}), 404
    mongo.db.carts.update_one({"user_id": user_id}, {"$set": {"items": cart['items']}})
    return jsonify({"message": "Cart updated."}), 200

@app.route('/api/cart', methods=['DELETE'])
@jwt_required()
def remove_from_cart():
    user_id = get_jwt_identity()
    data = request.get_json()
    product_id = data.get('product_id')
    if not product_id:
        return jsonify({"error": "Product ID required."}), 400
    cart = mongo.db.carts.find_one({"user_id": user_id})
    if not cart:
        return jsonify({"error": "Cart not found."}), 404
    new_items = [item for item in cart['items'] if str(item['product_id']) != product_id]
    mongo.db.carts.update_one({"user_id": user_id}, {"$set": {"items": new_items}})
    return jsonify({"message": "Removed from cart."}), 200

@app.route('/api/orders', methods=['POST'])
@jwt_required()
def place_order():
    user_id = get_jwt_identity()
    cart = mongo.db.carts.find_one({"user_id": user_id})
    if not cart or not cart.get('items'):
        return jsonify({"error": "Cart is empty."}), 400
    order = {
        "user_id": user_id,
        "items": cart['items'],
        "created_at": datetime.datetime.utcnow(),
        "status": "placed"
    }
    result = mongo.db.orders.insert_one(order)
    mongo.db.carts.update_one({"user_id": user_id}, {"$set": {"items": []}})  # Clear cart
    order['_id'] = str(result.inserted_id)
    return jsonify(order), 201

@app.route('/api/orders', methods=['GET'])
@jwt_required()
def get_orders():
    user_id = get_jwt_identity()
    orders = []
    for order in mongo.db.orders.find({"user_id": user_id}):
        order['_id'] = str(order['_id'])
        # Convert ObjectId to string for product_id in items
        for item in order['items']:
            item['product_id'] = str(item['product_id'])
        orders.append(order)
    return jsonify(orders), 200

@app.route('/api/orders/<order_id>', methods=['GET'])
@jwt_required()
def get_order(order_id):
    user_id = get_jwt_identity()
    order = mongo.db.orders.find_one({"_id": ObjectId(order_id), "user_id": user_id})
    if not order:
        return jsonify({"error": "Order not found."}), 404
    order['_id'] = str(order['_id'])
    for item in order['items']:
        item['product_id'] = str(item['product_id'])
    return jsonify(order), 200

# Admin: Get all users
@app.route('/api/admin/users', methods=['GET'])
@jwt_required()
def admin_get_users():
    user_id = get_jwt_identity()
    if not is_admin(user_id):
        return jsonify({"error": "Admin access required."}), 403
    users = []
    for user in mongo.db.users.find():
        user['_id'] = str(user['_id'])
        user.pop('password', None)
        users.append(user)
    return jsonify(users), 200

# Admin: Get all products
@app.route('/api/admin/products', methods=['GET'])
@jwt_required()
def admin_get_products():
    user_id = get_jwt_identity()
    if not is_admin(user_id):
        return jsonify({"error": "Admin access required."}), 403
    products = []
    for prod in mongo.db.products.find():
        prod['_id'] = str(prod['_id'])
        products.append(prod)
    return jsonify(products), 200

# Admin: Get all orders
@app.route('/api/admin/orders', methods=['GET'])
@jwt_required()
def admin_get_orders():
    user_id = get_jwt_identity()
    if not is_admin(user_id):
        return jsonify({"error": "Admin access required."}), 403
    orders = []
    for order in mongo.db.orders.find():
        order['_id'] = str(order['_id'])
        for item in order['items']:
            item['product_id'] = str(item['product_id'])
        orders.append(order)
    return jsonify(orders), 200

# Admin: Update user to admin
@app.route('/api/admin/users/<user_id>/make_admin', methods=['POST'])
@jwt_required()
def make_user_admin(user_id):
    admin_id = get_jwt_identity()
    if not is_admin(admin_id):
        return jsonify({"error": "Admin access required."}), 403
    result = mongo.db.users.update_one({"_id": ObjectId(user_id)}, {"$set": {"is_admin": True}})
    if result.matched_count == 0:
        return jsonify({"error": "User not found."}), 404
    return jsonify({"message": "User promoted to admin."}), 200

if __name__ == '__main__':
    app.run(debug=True)
