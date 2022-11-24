#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

typedef struct Tile {

    Vector2 position;
    bool isBlocked;
} Tile;

typedef struct Node {

    Vector2 position;
    Tile node[3][3];
} Node;

//----------------------------------------------------------------------------------
// Global Variable Declaration and Initialization
//----------------------------------------------------------------------------------
static const int screenWidth = 2560;
static const int screenHeight = 1440;

Node maze[4][4];

bool generationIsRunning = true;

void GenerateMaze ( void )
{

    for ( int i = 0; i < 4; i++ )
    {

        for ( int j = 0; j < 4; j++)
        {

            for ( int k = 0; k < 3; k++ )
            {

                for ( int l = 0; l < 3; l++)
                {

                    if ( k == 1 && l == 1 )
                    {

                        maze[i][j].node[k][l].isBlocked = false;
                    }

                    else if 
                    ( 

                        ( ( k == 0 || k == 2 ) && ( l == 0 || l == 2 ) ) || ( ( ( i == 0 || i == 3 ) && ( j == 0 || j == 3 ) ) && ( k != 1 && l != 1 ) ) // Overly-Complicated Logic
                    )

                    {

                        maze[i][j].node[k][l].isBlocked = true;
                    }

                    else if ( generationIsRunning )
                    {

                        maze[i][j].node[k][l].isBlocked = (rand() % (1 - 0 + 1)) + 0;
                    }
                };
            };
        };
    };

    generationIsRunning = false;
};

void DrawMaze ( void )
{
    ClearBackground(BLACK);

    Vector2 basePosition = { (float) 20, (float)  20 };

    for ( int i = 0; i < 4; i++ )
    {

        for ( int j = 0; j < 4; j++)
        {

            for ( int k = 0; k < 3; k++ )
            {

                for ( int l = 0; l < 3; l++)
                {
                    if ( ( maze[i][j].node[k][l].isBlocked == true ) && ( ( k == 0 && l == 0 ) || ( k == 2 && l == 2 ) ) || ( ( k == 0 && l == 2 ) || ( k == 2 && l == 0 ) ) ) { DrawRectangle ( 100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, YELLOW ); }
                    else if ( maze[i][j].node[k][l].isBlocked == true ) { DrawRectangle ( 100 * k + basePosition.x, 100 * l + basePosition.y, 20, 20, WHITE ); };
                };
            };

            basePosition.x += 200;
        };

        basePosition.x = 20;

        basePosition.y += 200;
    };
};

void Main ( void )
{
    // Initialization
    //---------------------------------------------------------
    InitWindow ( screenWidth, screenHeight, "Maze Generate" );

    SetTargetFPS ( 60 );
    //---------------------------------------------------------
    

    while ( !WindowShouldClose ( ) )    // Detect Window Close Button or ESC Key
    {
        // Generate
        GenerateMaze ( );

        // Draw
        BeginDrawing ( );
            DrawMaze ( );
        EndDrawing ( );
    }
} 



























int main ( void )
{
    Main ();
    
    return 0;
};