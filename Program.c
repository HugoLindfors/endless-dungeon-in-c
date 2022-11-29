#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

typedef const enum tile { left, centre_left, centre_right, right };
typedef const enum tile { up, middle_up, middle_down, down };
typedef const enum neighbor { up, right, down, left };

typedef struct Tile
{
    bool player_can_walk[4];
} Tile;

typedef struct Node
{
    Tile node[3][3];
} Node;

//----------------------------------------------------------------------------------
// Global Variable Declaration and Initialization
//----------------------------------------------------------------------------------
static const int screenWidth = 800;
static const int screenHeight = 450;

Node maze_block[4][4];

bool generationIsRunning = true;

// void GenerateMaze ( void )
// {

//     for ( int i = 0; i < 4; i++ )
//     {

//         for ( int j = 0; j < 4; j++)
//         {

//             for ( int k = 0; k < 3; k++ )
//             {

//                 for ( int l = 0; l < 3; l++)
//                 {

//                     // if it's a center-tile, then it's never blocked
//                     if ( k == 1 && l == 1 )
//                     {
//                         maze[i][j].node[k][l].isBlocked = false;
//                     }

//                     else if
//                     (

//                         ( ( k == 0 && l == 0 ) || ( k == 2 && l == 2 ) ) || // If tile is corner-tile, then it's always blocked
//                         ( ( i == 0 || i == 3 ) || ( j == 0 || j == 3 ) ) // If tile is outer-tile, then it's always blocked
//                     )

//                     {

//                         maze[i][j].node[k][l].isBlocked = true;
//                     }

//                     else if ( generationIsRunning )
//                     {

//                         maze[i][j].node[k][l].isBlocked = (rand() % 2);
//                     }

//                     if ( ( maze[i + 1][j].node[k - 1][l].isBlocked == false ) && ( l == 1 || k == 1 ) )
//                     {
//                         maze[i][j].node[k][l].isBlocked = false;

//                         maze[i][j].node[k][l].neighbor = North;
//                     }
//                 };
//             };
//         };
//     };

//     generationIsRunning = false;
// };

void GenerateMaze(void)
{
    // for every block

    // check every direction

    // if neigbor is blocked – block direction

    // else – randomize if direction is blocked

    // if you decide to block – save that data


    for (int x = left; x < right; x++ ) 
    {
        for (int y = up; y < down; y++ )
        {
            if (maze_block[left][up].neigbor[up] ==  )
        }
    }
}

void DrawMaze(void)
{
    ClearBackground(WHITE);

    Vector2 basePosition = {(float)20, (float)20};

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {

            for (int k = 0; k < 3; k++)
            {

                for (int l = 0; l < 3; l++)
                {
                    if ((maze[i][j].node[k][l].isBlocked == true) && ((k == 0 && l == 0) || (k == 2 && l == 2)) || ((k == 0 && l == 2) || (k == 2 && l == 0)))
                    {
                        DrawRectangle(100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, GREEN);
                    }
                    else if (maze[i][j].node[k][l].isBlocked == true)
                    {
                        DrawRectangle(100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, BLUE);
                    };
                };
            };

            basePosition.x += 300;
        };

        basePosition.x = 20;

        basePosition.y += 300;
    };
};

int main(void)
{
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "Maze Generate");

    SetTargetFPS(60);
    //---------------------------------------------------------

    while (!WindowShouldClose()) // Detect Window Close Button or ESC Key
    {
        // Check For Opt + Enter
        if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
        {
            // See What Display We Are On Right Now
            int display = GetCurrentMonitor();

            if (IsWindowFullscreen())
            {
                // If we are full screen, then go back to the windowed size
                SetWindowSize(screenWidth, screenHeight);
            }
            else
            {
                // If we are not full screen, set the window size to match the monitor we are on
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
            }

            // toggle the state
            ToggleFullscreen();
        }

        // Generate
        GenerateMaze();

        // Draw
        BeginDrawing();

        DrawMaze();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
};