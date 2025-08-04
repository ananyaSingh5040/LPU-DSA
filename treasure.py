import pygame
import random
import os

# Initialize pygame
pygame.init()

# Constants for the game
WIDTH, HEIGHT = 800, 600
COCONUT_WIDTH, COCONUT_HEIGHT = 100, 150
COCONUT_X = [200, 350, 500]  # X positions for coconuts
COCONUT_Y = 250  # Y position for coconuts
FPS = 30  # Frames per second for the game loop

# Colors
WHITE = (255, 255, 255)

# Load assets
coconut_img = pygame.image.load("coconut.png")  # Make sure to place your coconut image here
coin_img = pygame.image.load("coin.png")  # Place your coin image here
background_img = pygame.image.load("background.jpg")  # Background image

# Scale images (you may need to adjust this based on your image size)
coconut_img = pygame.transform.scale(coconut_img, (COCONUT_WIDTH, COCONUT_HEIGHT))
coin_img = pygame.transform.scale(coin_img, (50, 50))  # Scale coin image to fit
background_img = pygame.transform.scale(background_img, (WIDTH, HEIGHT))

# Set up the game window
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Find the Treasure")

# Fonts for text
font = pygame.font.SysFont("Arial", 30)

# Function to draw the coconuts and the coin
def draw_game(coconuts, coin_under):
    screen.blit(background_img, (0, 0))  # Draw background
    
    # Draw coconuts
    for i, coconut in enumerate(coconuts):
        screen.blit(coconut_img, (COCONUT_X[i], COCONUT_Y))
    
    # Draw coin if the coconut is not shuffled
    if coin_under is not None:
        coin_x = COCONUT_X[coin_under] + (COCONUT_WIDTH // 2) - 25
        coin_y = COCONUT_Y + (COCONUT_HEIGHT // 2) - 25
        screen.blit(coin_img, (coin_x, coin_y))

    pygame.display.flip()

# Main game loop
def main():
    running = True
    clock = pygame.time.Clock()

    score = 0
    guess_made = False

    while running:
        draw_game([coconut_img, coconut_img, coconut_img], None)

        # Event handling
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False

            if event.type == pygame.MOUSEBUTTONDOWN and not guess_made:
                x, y = pygame.mouse.get_pos()
                
                # Determine which coconut was clicked
                clicked_coconut = None
                for i in range(3):
                    if COCONUT_X[i] <= x <= COCONUT_X[i] + COCONUT_WIDTH and COCONUT_Y <= y <= COCONUT_Y + COCONUT_HEIGHT:
                        clicked_coconut = i
                        break

                if clicked_coconut is not None:
                    # Reveal the coin
                    if clicked_coconut == coin_position:
                        score += 1  # Increase score if the guess is correct
                    guess_made = True

        # Show the initial setup of the game
        if not guess_made:
            # Show coconuts before shuffle, then shuffle
            coconuts = [coconut_img, coconut_img, coconut_img]
            draw_game(coconuts, None)

            # Wait for a moment to show the coin position
            pygame.time.delay(1000)

            # Shuffle the coconuts
            shuffled_coconuts = [coconut_img, coconut_img, coconut_img]
            random.shuffle(shuffled_coconuts)
            global coin_position
            coin_position = random.randint(0, 2)  # Choose a random position for the coin
            
            # Draw shuffled coconuts
            draw_game(shuffled_coconuts, coin_position)
        
        # Display score
        score_text = font.render(f"Score: {score}", True, WHITE)
        screen.blit(score_text, (10, 10))
        
        if guess_made:
            result_text = font.render(f"You guessed {'correctly' if clicked_coconut == coin_position else 'wrong'}!", True, WHITE)
            screen.blit(result_text, (WIDTH // 2 - result_text.get_width() // 2, HEIGHT // 2 + 100))

            # Give some time before starting the next round
            pygame.time.delay(1000)

            # Reset the game for the next round
            guess_made = False

        clock.tick(FPS)  # Control the frame rate

    pygame.quit()

if __name__ == "__main__":
    main()
