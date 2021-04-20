#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int board_width = 66;
int board_height = 17;

int board[17][66] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
int temp_board[17][66];

void printToCoordinates(int y, int x, char text[])
{
    printf("\033[%d;%dH%s\n", y, x, text);
}

void printToCoordinates_int(int y, int x, int num)
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
    // printf("%d\n", board[0][0]);
    // printToCoordinates(10, 10, "HELLO");
    int count = 0;
    int iterations = 0;
    char score[20];
    for (int i = 0; i < board_height; i++)
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
                printToCoordinates(y + 3, x + 8, "O");
                // if (y > 2 || y < 20 || x > 7 || x < 74)
                // if (y > 3 || y < 19 || x > 8 || x < 73)
                if (y > 0 && y < board_height - 1 && x > 0 && x < board_width - 1)
                {
                    if (board[y][x] == 0)
                    {
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
                        if (count == 3)
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
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
                        if (count < 2)
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3)
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (y == 0)
                {
                    if (board[y][x] == 0)
                    {
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
                        if (count == 3)
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
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
                        if (count < 2)
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3)
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
                if (y == board_height - 1)
                {
                    if (board[y][x] == 0)
                    {
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
                        if (count == 3)
                        {
                            temp_board[y][x] = 1;
                        }
                    }
                    else if (board[y][x] == 1)
                    {
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
                        if (count < 2)
                        {
                            temp_board[y][x] = 0;
                        }
                        else if (count > 3)
                        {
                            temp_board[y][x] = 0;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < board_height; i++)
        {
            for (int j = 0; j < board_width; j++)
            {
                board[i][j] = temp_board[i][j];
            }
        }
        for (int y = 0; y < board_height; y++)
        {
            for (int x = 0; x < board_width; x++)
            {
                printToCoordinates_int(y + 3, x + 8, board[y][x]);
            }
        }
        load();
        printToCoordinates(20, 74, "#");
        iterations += 1;
        sprintf(score, "Generation: %d", iterations);
        printToCoordinates(21, 34, score);
        usleep(200000); /* Controls the time delay between frames. */
    }
}