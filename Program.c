#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

typedef enum neighbor { up, right, down, left } neighbor;
typedef enum maze_block_relative_position { first, second, third, last } maze_block_relative_position;
typedef enum tile_relative_position { t_first, t_middle, t_last } tile_relative_position;

typedef struct Tile
{
    Vector2 position;
    bool is_blocked;
} Tile;

typedef struct Node
{
    Vector2 position;
    bool is_walkable[4];
    Tile tile[3][3];
} Node;

static const int screen_width = 800;
static const int screen_height = 450;

Node maze_block[4][4];

void UpdateAndDrawMaze(void)
{
    // Update
    for (int row = 0; row < 4; row++)
    {
        for (int column = 0; column < 4; column++)
        {
            Node current_maze_block = maze_block[row][column];

            if ( row == first && column == first) 
            {
                maze_block[row][column].is_walkable[up] = false;
                maze_block[row][column].is_walkable[left] = false;
            }

            else if ( row == first && column == last) 
            {
                maze_block[row][column].is_walkable[up] = false;
                maze_block[row][column].is_walkable[right] = false;
            }

            else if ( row == last && column == first) 
            {
                maze_block[row][column].is_walkable[down] = false;
                maze_block[row][column].is_walkable[left] = false;
            }

            else if ( row == last && column == first) 
            {
                maze_block[row][column].is_walkable[down] = false;
                maze_block[row][column].is_walkable[right] = false;
            }

            for (int t_row = 0; t_row < 3; t_row++)
            {
                for (int t_column = 0; t_column < 3; t_column++)
                {

                    if ( t_row == t_first && t_column == t_first )
                    {
                        current_maze_block.tile[t_row][t_column].is_blocked = true;
                    }

                    else if ( t_row == t_first && t_column == t_last )
                    {
                        current_maze_block.tile[t_row][t_column].is_blocked = true;
                    }

                    else if ( t_row == t_last && t_column == t_first )
                    {
                        current_maze_block.tile[t_row][t_column].is_blocked = true;
                    }

                    else if ( t_row == t_last && t_column == t_last )
                    {
                        current_maze_block.tile[t_row][t_column].is_blocked = true;
                    }
                }
            }
        }
    }

    // Draw
    BeginDrawing();
        ClearBackground(BLUE);
        for (int row = 0; row < 4; row++)
        {
            for (int column = 0; column < 4; column++)
            {
                Node current_maze_block = maze_block[row][column];

                for (int t_row = 0; t_row < 3; t_row++)
                {
                    for (int t_column = 0; t_column < 3; t_column++)
                    {
                        if (current_maze_block.tile[t_row][t_column].is_blocked)
                        {
                            DrawRectangle((column * 10) * (t_column * 10), (row * 10) * (t_row * 10), 10, 10, WHITE);
                        }
                    }
                }
            }
        }
        
    EndDrawing();
}

int main(void)
{
    while (!WindowShouldClose())
    {
        InitWindow(screen_width, screen_height, "Maze Generator");

        SetTargetFPS(60);

        UpdateAndDrawMaze();
    }

    return 0;
}

// //----------------------------------------------------------------------------------
// // Types and Structures Definition
// //----------------------------------------------------------------------------------

// typedef const enum tile { left, centre_left, centre_right, right };
// typedef const enum tile { up, middle_up, middle_down, down };
// typedef const enum neighbor { up, right, down, left };

// typedef struct Tile
// {
//     bool player_can_walk[4];
// } Tile;

// typedef struct Node
// {
//     Tile node[3][3];
// } Node;

// //----------------------------------------------------------------------------------
// // Global Variable Declaration and Initialization
// //----------------------------------------------------------------------------------
// static const int screenWidth = 800;
// static const int screenHeight = 450;

// Node maze_block[4][4];

// bool generationIsRunning = true;

// // void GenerateMaze ( void )
// // {

// //     for ( int i = 0; i < 4; i++ )
// //     {

// //         for ( int j = 0; j < 4; j++)
// //         {

// //             for ( int k = 0; k < 3; k++ )
// //             {

// //                 for ( int l = 0; l < 3; l++)
// //                 {

// //                     // if it's a center-tile, then it's never blocked
// //                     if ( k == 1 && l == 1 )
// //                     {
// //                         maze[i][j].node[k][l].isBlocked = false;
// //                     }

// //                     else if
// //                     (

// //                         ( ( k == 0 && l == 0 ) || ( k == 2 && l == 2 ) ) || // If tile is corner-tile, then it's always blocked
// //                         ( ( i == 0 || i == 3 ) || ( j == 0 || j == 3 ) ) // If tile is outer-tile, then it's always blocked
// //                     )

// //                     {

// //                         maze[i][j].node[k][l].isBlocked = true;
// //                     }

// //                     else if ( generationIsRunning )
// //                     {

// //                         maze[i][j].node[k][l].isBlocked = (rand() % 2);
// //                     }

// //                     if ( ( maze[i + 1][j].node[k - 1][l].isBlocked == false ) && ( l == 1 || k == 1 ) )
// //                     {
// //                         maze[i][j].node[k][l].isBlocked = false;

// //                         maze[i][j].node[k][l].neighbor = North;
// //                     }
// //                 };
// //             };
// //         };
// //     };

// //     generationIsRunning = false;
// // };

// void GenerateMaze(void)
// {
//     // for every block

//     // check every direction

//     // if neigbor is blocked – block direction

//     // else – randomize if direction is blocked

//     // if you decide to block – save that data


//     for (int x = left; x < right; x++ ) 
//     {
//         for (int y = up; y < down; y++ )
//         {
//             if (maze_block[left][up].neigbor[up] ==  )
//         }
//     }
// }

// void DrawMaze(void)
// {
//     ClearBackground(WHITE);

//     Vector2 basePosition = {(float)20, (float)20};

//     for (int i = 0; i < 4; i++)
//     {

//         for (int j = 0; j < 4; j++)
//         {

//             for (int k = 0; k < 3; k++)
//             {

//                 for (int l = 0; l < 3; l++)
//                 {
//                     if ((maze[i][j].node[k][l].isBlocked == true) && ((k == 0 && l == 0) || (k == 2 && l == 2)) || ((k == 0 && l == 2) || (k == 2 && l == 0)))
//                     {
//                         DrawRectangle(100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, GREEN);
//                     }
//                     else if (maze[i][j].node[k][l].isBlocked == true)
//                     {
//                         DrawRectangle(100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, BLUE);
//                     };
//                 };
//             };

//             basePosition.x += 300;
//         };

//         basePosition.x = 20;

//         basePosition.y += 300;
//     };
// };

// int main(void)
// {
//     // Initialization
//     //---------------------------------------------------------
//     InitWindow(screenWidth, screenHeight, "Maze Generate");

//     SetTargetFPS(60);
//     //---------------------------------------------------------

//     while (!WindowShouldClose()) // Detect Window Close Button or ESC Key
//     {
//         // Check For Opt + Enter
//         if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
//         {
//             // See What Display We Are On Right Now
//             int display = GetCurrentMonitor();

//             if (IsWindowFullscreen())
//             {
//                 // If we are full screen, then go back to the windowed size
//                 SetWindowSize(screenWidth, screenHeight);
//             }
//             else
//             {
//                 // If we are not full screen, set the window size to match the monitor we are on
//                 SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
//             }

//             // toggle the state
//             ToggleFullscreen();
//         }

//         // Generate
//         GenerateMaze();

//         // Draw
//         BeginDrawing();

//         DrawMaze();

//         EndDrawing();
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     CloseWindow(); // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// };


// // Update
//         for (int x = 0; x < 4; x++)
//         {
//             for (int y = 0; y < 4; y++)
//             {
//                 if (x == 0 && y == 0) // check for upper-left-corner node
//                 {
//                     maze_block[x][y].player_can_walk[up] = false;
//                     maze_block[x][y].player_can_walk[left] = false;
//                 }

//                 else if (x == 3 && y == 0) // check for upper-right-corner node
//                 {
//                     maze_block[x][y].player_can_walk[up] = false;
//                     maze_block[x][y].player_can_walk[right] = false;
//                 }

//                 else if (x == 0 && y == 3) // check for lower-left-corner node
//                 {
//                     maze_block[x][y].player_can_walk[down] = false;
//                     maze_block[x][y].player_can_walk[left] = false;
//                 }

//                 else if (x == 3 && y == 3) // check for lower-right-corner node
//                 {
//                     maze_block[x][y].player_can_walk[down] = false;
//                     maze_block[x][y].player_can_walk[right] = false;
//                 }


//                 else if (y == 0) // check for upper-edge nodes
//                 {
//                     maze_block[x][y].player_can_walk[up] = false;
//                 }

//                 else if (x == 3) // check for right-edge nodes
//                 {
//                     maze_block[x][y].player_can_walk[right] = false;
//                 }

//                 else if (x == 3) // check for lower-edge nodes
//                 {
//                     maze_block[x][y].player_can_walk[down] = false;
//                 }

//                 else if (x == 3) // check for left-edge nodes
//                 {
//                     maze_block[x][y].player_can_walk[left] = false;
//                 }
//             }
//         }


// // Draw
//         BeginDrawing();
//         ClearBackground(BLUE);
//         for (int x = 0; x < 4; x++)
//         {
//             for (int y = 0; y < 4; y++)
//             {
//                 maze_block[x][y].position.x = 15 * x;
//                 maze_block[x][y].position.y = 15 * y;

//                 maze_block[x][y].tile[1][1].position.x = 30 * x + 15;
//                 maze_block[x][y].tile[1][1].position.y = 30 * y + 15;

//                 DrawRectangle(maze_block[x][y].tile[1][1].position.x, maze_block[x][y].tile[1][1].position.y, 15, 15, WHITE);
//             }
//         }
//         EndDrawing();