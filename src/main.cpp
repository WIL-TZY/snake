#include <iostream>
#include <raylib.h>

// Necessary to use all the classes, functions, and other elements from the std namespace without explicitly specifying std:: before each one
using namespace std;

// Colors in raylib are represented by a struct named 'Color'
// struct Color {red, green, blue, alpha}
// This struct contains four unsigned byte components: red, green, blue and alpha
// It works similarly to RGBA
Color lightGreen = {173, 204, 96, 25};
Color darkGreen = {43, 51, 24, 255};
Color white = {255, 255, 255, 255};

// Creating a grid
int cellSize = 30; // 30px
int cellCount = 25; // Area: 30*25 = 750px by 750px

// Boolean variable to track the Debug Mode
bool debugMode = false;

// Press 'D' key to toggle the Debug Mode
void ToggleDebugMode()
{
    if (IsKeyPressed(KEY_D))
    {
        debugMode = !debugMode;
    }
}

void DrawGrid()
{
    if (debugMode)
    {
        // Draw vertical lines
        for (int x = 0; x <= cellCount; x++)
        {
            int xPos = x * cellSize;
            DrawLine(xPos, 0, xPos, cellSize * cellCount, white);
        }

        // Draw horizontal lines
        for (int y = 0; y <= cellCount; y++)
        {
            int yPos = y * cellSize;
            DrawLine(0, yPos, cellSize * cellCount, yPos, white);
        }
    }
}

class Food {
// raylib Vector2 struct 
// struct Vector2 {x, y}
// It's a data structure that contains x and y attributes 
public:
    // Access the food position with: position.x & position.y
    Vector2 position; // The numbers represent cells, not pixels. Count starts at 0. E.g.> {5, 6}
    Texture2D texture;

    // Constructor
    Food() {
        // In raylib, an image is a data structure that contains the pixel data of a graphical image
        // Once loaded, an image can be used to create a texture, which is a GPU resource than can be rendered
        Image image = LoadImage("sprites/food.png");
        // This function takes an image and returns a Texture2D struct that can be used for rendering
        // A Texture2D represents an image loaded into the graphics memory, it's very quickly processed
        texture = LoadTextureFromImage(image);
        // Once the image has become the texture, we can free some memory by removing it
        UnloadImage(image);
        position = GenerateRandomPos(); // ---> Set below
    }
    
    // Destructor (~) - A special function in C++ called everytime an object is destroyed
    // This destructor is used to unload the texture when the object is destroyed
    ~Food(){
        UnloadTexture(texture);
    }

    void Draw() {
        DrawTexture(texture, position.x * cellSize, position.y * cellSize, WHITE);
        // If you want to display the food as a simple rectangle, uncomment this
        // DrawRectangle(position.x * cellSize, position.y * cellSize, cellSize, cellSize, darkGreen);
    }

    // Randomizing position
    Vector2 GenerateRandomPos() {
        // This raylib function generates a random number based on a given range
        // A number from 0 to 24 because the grid has 25 cells on each row
        float x = GetRandomValue(0, cellCount - 1);
        float y = GetRandomValue(0, cellCount - 1);
        return Vector2{x, y};
    }
};

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

    // -------------------------- Initialization --------------------------
    InitWindow(cellSize*cellCount, cellSize*cellCount, "Snake");
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

    // Create an instance (object) of the food class
    Food food = Food();

    // -------------------------- Game Loop --------------------------
    // 1. Event Handling
    // 2. Updating Positions
    // 3. Drawing Objects

    // Checking if pressing ESC or if clicking on the window close icon
    // If it returns true, the while loop breaks and the game will end
    while (WindowShouldClose() == false ) { 

        // Toggle debug mode when 'D' key is pressed
        ToggleDebugMode();
        
        // -------------------------- Drawing --------------------------
        BeginDrawing(); // Creates a blank canvas where the objects will be drawn to

        // Painting the game window with a green color
        // This is the first thing that happens every frame
        // Successfully cleans up the previous frame's graphics
        // So the next frame can be drawn without any old artefacts or remnants
        ClearBackground(lightGreen);

        // Draw the grid
        DrawGrid();

        // Draw the food
        food.Draw();

        EndDrawing(); // Destroys the canvas

    }

    CloseWindow();

    return 0;
}