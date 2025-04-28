#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

void clear_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    for(int row = 0; row < size; row++)
    {
        for(int col = 0; col < size; col++)
        {

            board[row][col] = 0;
        }
    }
}

void print_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    int block_size = 1;
    while (block_size * block_size < size)
    {
        block_size++;
    }

    for(int row = 0; row < size; row++)
        {
        if(row % block_size == 0 && row != 0)
        {
            for (int i = 0; i < size * 3 + block_size - 1; i++)
            {
                printf("-");
            }
            printf("\n");
        }

        for (int col = 0; col < size; col++)
        {

            if (col % block_size == 0 && col != 0)
            {
                printf(" | ");
            }
            if (board[row][col] == 0)
            {
                printf(" . ");
            }
            else
            {
                printf("%2d ", board[row][col]);
            }
        }
        printf("\n");
    }
}

bool is_valid(int size, int board[MAX_SIZE][MAX_SIZE], int row, int col, int num)
{
    // TODO
}

bool fill_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    // TODO
}

void remove_numbers(int size, int board[MAX_SIZE][MAX_SIZE], int difficulty)
{
    // TODO
}

void save_game(int size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    // TODO
}

bool load_game(int* size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    // TODO

}
