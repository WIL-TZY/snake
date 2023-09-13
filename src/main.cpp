#include <iostream>
#include <raylib.h>

using namespace std;

/*
    SNAKE GAME - STEPS
    1. Create a blank canvas & game loop
    2. Create the food 
    3. Create the snake 
    4. Move the snake
    5. Make the snake eat the food
    6. Make the snake grow longer
    7. Checking for collision with edges & tail
    8. Add title & framing
    9. Score
    10. Add sounds
*/

/*
    Game Structure - 2 parts
    1st part - Initialization
    - Defining the variables needed
    - Creating the game objects

    2nd part - Game Loop
    - Updates the positions of the game objects
    - Checking for collisions
*/

int main() {
    // Testing setup
    cout << "Starting the game..." << endl;

    // Initialization
    InitWindow(750, 750, "Snake");
    // raylib 4.5 configs
    // (Device) Display Size:      1920 x 1080
    // Screen size (Game Window):   750 x 750
    // Render size:                 750 x 750 
    // Viewport offsets:              0 x 0
    // Default font:                224 glyphs

    // Timing function
    // The game speed usually depends on the speed of the computer
    // By defining a frame rate, the game speed is normalized in all machines
    SetTargetFPS(60); 

    // Game Loop
    // 1. Event Handling
    // 2. Updating Positions
    // 3. Drawing Objects

    // Checking if pressing ESC or if clicking on the window close icon
    // If it returns true, the while loop breaks and the game will end
    while (WindowShouldClose() == false ) { 


        BeginDrawing(); // Creates a blank canvas where the objects will be drawn to




        EndDrawing(); // Destroys the canvas

    }

    CloseWindow();

    return 0;
}