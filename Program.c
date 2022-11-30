#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
typedef struct Node {
    Vector2 position;
    bool isColored;
} Node;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

Node maze_block[4][4];

void GenerateMaze(void)
{
    for (size_t y = 0; y < 4; y++)
    {
        for (size_t x = 0; x < 4; x++)
        {
            maze_block[y][x].isColored = rand() % 2;
        }
    }
}

void DrawMaze(void)
{
    BeginDrawing();

        ClearBackground(BLUE);

        for (size_t y = 0; y < 4; y++)
        {
            for (size_t x = 0; x < 4; x++)
            {
                if (maze_block[y][x].isColored)
                {
                    DrawRectangle(x * 10, y * 10, 5, 5, WHITE);
                };
            }
        }

    EndDrawing();
}

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    puts("test_1");

    while ( WindowShouldClose() )
    {
        InitWindow(screenWidth, screenHeight, "Maze Generate");

        SetTargetFPS(60);

        GenerateMaze();

        DrawMaze();
    }
    
    return 0;
};