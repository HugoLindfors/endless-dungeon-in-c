#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

typedef struct Tile
{
    bool isWalkable[3][3];

} Tile;

typedef struct Maze
{
    Tile maze[4][4];
} Maze;

//----------------------------------------------------------------------------------
// Global Variable Declaration and Initialization
//----------------------------------------------------------------------------------
static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 450;

//------------------------------------------------------------------------------------
// Program Main Entry Point
//------------------------------------------------------------------------------------

int main ( void )
{
    Tile maze[4][4];

    for ( int i = 0; i < 4; i++ )
    {
        for ( int j = 0; i < 4; j++ )
        {
            for ( int k = 0; k < 3; k++ )
            {
                for ( int l = 0; l < 3; l++ )
                {
                    if ( k == 2 && l == 2 ) { maze[i][j].isWalkable[k][l] = true; }
                    else { maze[i][j].isWalkable[k][l] = false; }
                }
            }
        }
    }

    // Initialization
    //---------------------------------------------------------
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Maze Generation" );

    SetTargetFPS(60); 
    //---------------------------------------------------------

    while ( !WindowShouldClose() )    // Detect Window Close Button or ESC Key
    {
        BeginDrawing();
            DrawText( "Test", 20, 20, 20, WHITE );

            for ( int i = 0; i < 4; i++ )
            {
                for ( int j = 0; j < 4; j++ )
                {
                    for ( int k = 0; k < 3; k++ )
                    {
                        for (int l = 0; l < 3; l++ )
                        {
                            if ( maze[i][j].isWalkable[k][l] )
                            {
                                DrawCircle( i * 50 + 20, j * 50 + 20, 5, BLACK );
                            }

                            else
                            {
                                DrawCircle( i * 50 + 20, j * 50 + 20, 5, WHITE );
                            }
                        }
                    }
                }
            }
        EndDrawing();
    }

    return 0;
}