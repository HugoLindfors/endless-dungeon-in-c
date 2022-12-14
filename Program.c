#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include <time.h>
#include <math.h>

int screen_width = 800, screen_height = 450;
const char screen_title[12] = "Endless Maze";

typedef struct Node { bool _has_lower_edge, _has_right_edge; } Node;
typedef struct Player { Vector2 _position; Vector2 _velocity; int _active_row, _active_column; } Player;


Node node[4][4];
Player player;

bool game_is_completed;

void InitMaze(void)
{
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t column = 0; column < 4; column++)
        {
            if (row == 4)
            {
                node[row][column]._has_lower_edge = false;
            }

            else
            {
                node[row][column]._has_lower_edge = true;
            }

            if (column == 4)
            {
                node[row][column]._has_right_edge = false;
            }

            else
            {
                node[row][column]._has_right_edge = true;
            }
        }
    }
}

void CheckUpLogic(int row, int column)
{
    if (row != 0 && column != 0)
    {
        if (node[row - 1][column]._has_lower_edge && node[row][column - 1]._has_right_edge)
        {
            node[row][column]._has_lower_edge = false;
            node[row][column]._has_right_edge = false;
        }

        if (node[row - 1][column]._has_lower_edge)
        {
            int random_variable = rand() % 2;

            if (random_variable)
            {
                node[row][column]._has_lower_edge = false;
            }

            if (!random_variable)
            {
                node[row][column]._has_right_edge = false;
            }
        }

        if (node[row][column - 1]._has_right_edge)
        {
            int random_variable = rand() % 2;

            if (random_variable)
            {
                node[row][column]._has_lower_edge = false;
            }

            if (!random_variable)
            {
                node[row][column]._has_right_edge = false;
            }
        }
    }
    else
    {
        node[row][column]._has_lower_edge = false;
        node[row][column]._has_right_edge = false;
    }
}

void CleanUpMaze(void)
{
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t column = 0; column < 4; column++)
        {
            CheckUpLogic(row, column);
        }
    }
}

void GenerateMaze(void)
{
    for (size_t row = 0; row < 4; row++)
    {
        for (size_t column = 0; column < 4; column++)
        {
            if (row != 4)
            {
                node[row][column]._has_lower_edge = rand() % 2; // random true/false value
            }

            if (column != 4)
            {
                node[row][column]._has_right_edge = rand() % 2; // random true/false value
            }
        }
    }

    CleanUpMaze();
}

void DrawSurrounding(void)
{
    DrawRectangle(0, 0, 400, 5, WHITE);
    DrawRectangle(0, 0, 5, 400, WHITE);
    DrawRectangle(0, 400, 400, 5, WHITE);
    DrawRectangle(400, 0, 5, 400, WHITE);
}

void DrawGoal(void)
{
    DrawRectangle(320, 320, 60, 60, RED);
}

void DrawMaze(void)
{
    DrawSurrounding();

    for (size_t row = 0; row < 4; row++)
    {
        for (size_t column = 0; column < 4; column++)
        {
            if (node[row][column]._has_lower_edge)
            {
                DrawRectangle(100 * column, 100 * row, 100, 5, WHITE);
            }

            if (node[row][column]._has_right_edge)
            {
                DrawRectangle(100 * column, 100 * row, 5, 100, WHITE);
            }
        }
    }

    DrawGoal();
}

void WinGame(void)
{
    if (player._position.x >= 350 && player._position.y >= 350 ) { game_is_completed = true; }
}

void DrawPlayer(void) 
{
    DrawRectangle(player._position.x - 30, player._position.y - 30, 60, 60, WHITE);
}

void MovePlayer(void)
{
    // UP ONE ROW
    if (IsKeyPressed(KEY_W) && player._position.y > 50 && !node[player._active_row][player._active_column]._has_lower_edge) 
    { 
        player._position.y -= 100; 
        player._active_row--;
    }

    // LEFT ONE COLUMN
    if (IsKeyPressed(KEY_A) && player._position.x > 50 && !node[player._active_row][player._active_column]._has_right_edge) 
    { 
        player._position.x -= 100; 
        player._active_column--;
    }

    // DOWN ONE ROW
    if (IsKeyPressed(KEY_S) && player._position.y < 350 && !node[player._active_row + 1][player._active_column]._has_lower_edge) 
    { 
        player._position.y += 100;
        player._active_row++;
    }

    // RIGHT ONE COLUMN
    if (IsKeyPressed(KEY_D) && player._position.x < 350 && !node[player._active_row][player._active_column + 1]._has_right_edge) 
    { 
        player._position.x += 100;
        player._active_column++;
    }
}

int main(void)
{
    game_is_completed = false;

    player._position = (Vector2){50, 50};

    player._active_row = player._active_column = 0;

    InitWindow(screen_width, screen_height, screen_title);

    SetTargetFPS(60);

    InitMaze();
    
    GenerateMaze();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        if (!game_is_completed)
        {
            ClearBackground(BLACK);
            DrawMaze();
            MovePlayer();
            DrawPlayer();
            WinGame();
        }

        if (game_is_completed)
        {
            ClearBackground(BLACK);
            DrawText("You won!", GetScreenWidth() / 2, GetScreenHeight() / 2, 16, GREEN);
            main();
        }

        EndDrawing();
    }

    return 0;
}