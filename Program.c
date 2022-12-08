#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

typedef enum Neighbor { up, left, down, right } Neighbor;

typedef struct Edge { Vector2 position; float width; float height; Color color; bool is_colored; } Edge;

typedef struct Node { Vector2 position; float width; float height; Color color; bool is_colored; Edge edge[4]; } Node;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
static const int screen_width = 800;
static const int screen_height = 450;

static const edge_long_side = 100;
static const edge_short_side = 5;

Node maze_block[4][4];

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------

void InitMaze(void)
{
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++) // col(umn)
        {
            maze_block[row][col].position.x = col * 100;
            maze_block[row][col].position.y = row * 100;

            maze_block[row][col].width = 100;
            maze_block[row][col].height = 100;

            maze_block[row][col].color = RED;
            maze_block[row][col].is_colored = true;

            for (size_t i_edge = 0; i_edge < 4; i_edge++)
            {
                switch (i_edge)
                {
                case up:
                    maze_block[row][col].edge[i_edge].position.x = col * 100;
                    maze_block[row][col].edge[i_edge].position.y = row * 100;

                    maze_block[row][col].edge[i_edge].width = edge_long_side;
                    maze_block[row][col].edge[i_edge].height = edge_short_side;

                    maze_block[row][col].edge[i_edge].color = WHITE;
                    maze_block[row][col].edge[i_edge].is_colored = true;
                    break;

                case left:
                    maze_block[row][col].edge[i_edge].position.x = col * 100;
                    maze_block[row][col].edge[i_edge].position.y = row * 100;

                    maze_block[row][col].edge[i_edge].width = edge_short_side;
                    maze_block[row][col].edge[i_edge].height = edge_long_side;

                    maze_block[row][col].edge[i_edge].color = WHITE;
                    maze_block[row][col].edge[i_edge].is_colored = true;
                    break;

                case down:
                    maze_block[row][col].edge[i_edge].position.x = col * 100;
                    maze_block[row][col].edge[i_edge].position.y = row * 100 + 100;

                    maze_block[row][col].edge[i_edge].width = edge_long_side;
                    maze_block[row][col].edge[i_edge].height = edge_short_side;

                    maze_block[row][col].edge[i_edge].color = WHITE;
                    maze_block[row][col].edge[i_edge].is_colored = true;
                    break;

                case right:
                    maze_block[row][col].edge[i_edge].position.x = col * 100 + 100;
                    maze_block[row][col].edge[i_edge].position.y = row * 100;

                    maze_block[row][col].edge[i_edge].width = edge_short_side;
                    maze_block[row][col].edge[i_edge].height = edge_long_side;

                    maze_block[row][col].edge[i_edge].color = WHITE;
                    maze_block[row][col].edge[i_edge].is_colored = true;

                    // The code above is fine, but it will leave an uncolored square at the bottom right. To compensate the right edge of the lowermost, rightmost maze_block is lenghtened by one edge_short_side
                    if (row == 3 && col == 3)
                    {
                        maze_block[row][col].edge[i_edge].height = edge_long_side + edge_short_side;
                    }

                    break;
                }
            }
            
        }  
    }   
}

void GenerateMaze(void)
{
    
}

void DrawMaze(void)
{
    ClearBackground(BLACK);

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t col = 0; col < 4; col++) // col(umn)
        {
            DrawRectangle(maze_block[row][col].position.x, maze_block[row][col].position.y, maze_block[row][col].width, maze_block[row][col].height, maze_block[row][col].color);

            for (size_t i_edge = 0; i_edge < 4; i_edge++)
            {
                DrawRectangle(maze_block[row][col].edge[i_edge].position.x, maze_block[row][col].edge[i_edge].position.y, maze_block[row][col].edge[i_edge].width, maze_block[row][col].edge[i_edge].height, maze_block[row][col].edge[i_edge].color);
            }
            
        }  
    }
}

int main(void)
{
    InitWindow(screen_width, screen_height, "Endless Maze");

    InitMaze();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Generate
        GenerateMaze();

        // Draw
        BeginDrawing();
        DrawMaze();
        EndDrawing();
    }

    return 0;
}