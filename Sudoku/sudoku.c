#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
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
      int block_size = 1;
    while (block_size * block_size < size)
        block_size++;

    for (int i = 0; i < size; i++)
    {
        if (board[row][i] == num)
            return false;
    }

    for (int i = 0; i < size; i++)
    {
        if (board[i][col] == num)
            return false;
    }

    int start_row = (row / block_size) * block_size;
    int start_col = (col / block_size) * block_size;

    for (int i = 0; i < block_size; i++)
    {
        for (int j = 0; j < block_size; j++)
        {
            if (board[start_row + i][start_col + j] == num)
                return false;
        }
    }

    return true;
}

void mix(int *array, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

bool fill_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            if (board[row][col] == 0)
            {
                int numbers[MAX_SIZE];
                for (int i = 0; i < size; i++)
                    numbers[i] = i + 1;

                mix(numbers, size);

                for (int i = 0; i < size; i++)
                {
                    int num = numbers[i];

                    if (is_valid(size, board, row, col, num))
                    {
                        board[row][col] = num;

                        if (fill_board(size, board))
                            return true;

                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

void remove_numbers(int size, int board[MAX_SIZE][MAX_SIZE], int difficulty)
{
    int total_cells = size * size;
    int clues_to_keep;

    switch (difficulty)
    {
        case 1:
            clues_to_keep = (int)(0.6 * total_cells);
            break;
        case 2:
            clues_to_keep = (int)(0.45 * total_cells);
            break;
        case 3:
            clues_to_keep = (int)(0.3 * total_cells);
            break;
        default:
            clues_to_keep = (int)(0.45 * total_cells);
    }

    int cells_to_remove = total_cells - clues_to_keep;

    while (cells_to_remove > 0)
    {
        int row = rand() % size;
        int col = rand() % size;

        if (board[row][col] != 0)
        {
            board[row][col] = 0;
            cells_to_remove--;
        }
    }
}

void save_game(int size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    // TODO
}

bool load_game(int* size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    // TODO

}
