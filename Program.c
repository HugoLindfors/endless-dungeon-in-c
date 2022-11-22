#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------
// typedef struct Node
// {
//     Vector2 position;
// };

// typedef struct Edge
// {
//     Vector2 position;
//     const float length;
//     const float width;
// };

//----------------------------------------------------------------------------------
// Global Variable Declaration and Initialization
//----------------------------------------------------------------------------------
static const int SCREEN_WIDTH = 800;
static const int SCREEN_HEIGHT = 450;

// static const int EDGE_LENGTH = 10;
// static const int EDGE_WIDTH = 1;

//------------------------------------------------------------------------------------
// Program Main Entry Point
//------------------------------------------------------------------------------------
int main ( void )
{
    // Initialization
    //---------------------------------------------------------
    InitWindow( SCREEN_WIDTH, SCREEN_HEIGHT, "Maze Generation" );



    SetTargetFPS(60); 
    //---------------------------------------------------------

    while ( !WindowShouldClose() )    // Detect Window Close Button or ESC Key
    {

    }

    return 0;
}