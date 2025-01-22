#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    // c= a-b;
    // if(c>=0)
    // cout<<c<<endl;
    // else
    // cout<<"0"<<endl;
    a > b ? cout << (a - b) << endl : cout << "0" << endl;

    return 0;
}