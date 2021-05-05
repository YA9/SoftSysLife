/* Author: Yehya Albakri
Life is an implementation of Conway's Game of Life.

Resources used:
https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life

command to run: gcc life.c -o life && ./life

Notes:
- Cells can pass through walls and pop up on the other side of the board.

Instructions:
- Write your starting configuration in the 2D array "board". 0's represent dead cells and 1's represent living cells.
- Run the command to run.
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int board_width = 66;
int board_height = 17;

int board[17][66] =
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int temp_board[17][66];

void printToCoordinates(int y, int x, char text[]) /* Prints a character to coordinates on the board. */
{
    printf("\033[%d;%dH%s\n", y, x, text);
}

void printToCoordinates_int(int y, int x, int num) /* Prints an integer to coordinates on the board. */
{
    printf("\033[%d;%dH%d\n", y, x, num);
}

void load() /* Generates Game's frame. */
{
    for (int i = 7; i < 75; i++)
    {
        printToCoordinates(2, i, "=");
    }
    for (int i = 3; i < 20; i++)
    {
        printToCoordinates(i, 74, "|");
    }
    for (int i = 3; i < 20; i++)
    {
        printToCoordinates(i, 7, "|");
    }
    for (int i = 7; i < 75; i++)
    {
        printToCoordinates(20, i, "=");
    }
    printf("\n");
}

int main()
{
    int frame_delay = 100000; /* Delay between terminal frames in milliseconds. */
    int count = 0;
    int iterations = 0;                    /* Counts the number of generations that have passed. */
    char score[20];                        /* String to store the string "Score: " and the number of generations passed. */
    for (int i = 0; i < board_height; i++) /* Copies the game board into a temporary variable. */
    {
        for (int j = 0; j < board_width; j++)
        {
            temp_board[i][j] = board[i][j];
        }
    }
    while (1)
    {
        system("clear"); /* Clears the terminal */
        for (int y = 0; y < board_height; y++)
        {
            for (int x = 0; x < board_width; x++)
            {
                if (y > 0 && y < board_height - 1 && x > 0 && x < board_width - 1) /* Scans the board without counting the outside perimiter. */
                {
                    if (board[y][x] == 0)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count == 3) /* Changes the cell at board[y][x] to 1 if there are exactly 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count < 2) /* Changes the cell at board[y][x] to 0 if there are less than 2 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3) /* Changes the cell at board[y][x] to 0 if there are more than 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (y == 0) /* Scans the board at the top side of the perimeter and includes the bottom side of the perimeter in the count. */
                {
                    if (board[y][x] == 0)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[board_height - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[board_height - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[board_height - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count == 3) /* Changes the cell at board[y][x] to 1 if there are exactly 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[board_height - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[board_height - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[board_height - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count < 2) /* Changes the cell at board[y][x] to 0 if there are less than 2 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3) /* Changes the cell at board[y][x] to 0 if there are more than 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (y == board_height - 1) /* Scans the board at the bottom side of the perimeter and includes the top side of the perimeter in the count. */
                {
                    if (board[y][x] == 0)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count == 3) /* Changes the cell at board[y][x] to 1 if there are exactly 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[0][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count < 2) /* Changes the cell at board[y][x] to 0 if there are less than 2 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3) /* Changes the cell at board[y][x] to 0 if there are more than 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (x == 0) /* Scans the board at the left side of the perimeter and includes the right side of the perimeter in the count. */
                {
                    if (board[y][x] == 0)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count == 3) /* Changes the cell at board[y][x] to 1 if there are exactly 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x + 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][board_width - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count < 2) /* Changes the cell at board[y][x] to 0 if there are less than 2 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3) /* Changes the cell at board[y][x] to 0 if there are more than 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (x == board_width - 1) /* Scans the board at the right side of the perimeter and includes the left side of the perimeter in the count. */
                {
                    if (board[y][x] == 0)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count == 3) /* Changes the cell at board[y][x] to 1 if there are exactly 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
                        /* Adds to the count the number of surrounding cells of board[y][x] that equal 1. */
                        count = 0;
                        if (board[y - 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y - 1][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][0] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x] == 1)
                        {
                            count += 1;
                        }
                        if (board[y + 1][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (board[y][x - 1] == 1)
                        {
                            count += 1;
                        }
                        if (count < 2) /* Changes the cell at board[y][x] to 0 if there are less than 2 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3) /* Changes the cell at board[y][x] to 0 if there are more than 3 living cells surrounding it. */
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < board_height; i++) /* Transfers the temp board back into the original board. This process is done because the behavior would change if cells change as the program is still scanning. */
        {
            for (int j = 0; j < board_width; j++)
            {
                board[i][j] = temp_board[i][j];
            }
        }
        for (int y = 0; y < board_height; y++) /* Prints cells that are alive to their corresponding coordinates in the terminal. */
        {
            for (int x = 0; x < board_width; x++)
            {
                if (board[y][x] == 1)
                {
                    printToCoordinates(y + 3, x + 8, "#");
                }
            }
        }
        load();                                         /* Prints the game frame. */
        iterations += 1;                                /* Adds 1 to the number of generations that have passed. */
        sprintf(score, "Generation: %d\n", iterations); /* Saves the new generation number to the score string. */
        printToCoordinates(21, 34, score);              /* Prints the current number of generations passed below the game board. */
        usleep(frame_delay);
        /* Controls the time delay between frames. */
        if (iterations == 150) /* Runs the game for a given number of iterations. */
        {
            break;
        }
    }
}