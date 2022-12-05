#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

typedef enum neighbor
{
    up,
    right,
    down,
    left
} neighbor;

typedef struct Node
{
    Vector2 position;
    bool is_colored;
    float width;
    float height;
    Color color;
    bool is_blocked[4];
} Node;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screen_width = 800;
static const int screen_height = 450;

Node maze_block[4][4];

void InitMaze(void) // Initialize maze
{
    int row_height = 64, column_width = GetScreenWidth() / 12; // Twelve 'cause why not? (Bootstrap uses 12 columns per row)

    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            maze_block[row][column].position.y = row * row_height;
            maze_block[row][column].position.x = column * column_width;

            maze_block[row][column].width = column_width;
            maze_block[row][column].height = row_height;

            maze_block[row][column].color = WHITE;
        }
    }
}

void GenerateMaze(void) // Generate maze
{
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            
        }
    }
}

void DrawMaze(void) // Draw maze
{
    ClearBackground(BLACK);

    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            DrawRectangle(maze_block[row][column].position.x, maze_block[row][column].position.y, maze_block[row][column].width, maze_block[row][column].height, maze_block[row][column].color);
        }
    }
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialize
    InitWindow(screen_width, screen_height, "Endless Maze");

    InitMaze();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        GenerateMaze();

        // Draw
        BeginDrawing();
        DrawMaze();
        EndDrawing();
    }

    return 0;
};