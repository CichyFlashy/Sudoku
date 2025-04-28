#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sudoku.h"

void clear_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    //TODO
}

void print_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    //TODO
}

bool is_valid(int size, int board[MAX_SIZE][MAX_SIZE], int row, int col, int num)
{
    //TODO
}

bool fill_board(int size, int board[MAX_SIZE][MAX_SIZE])
{
    //TODO
}

void remove_numbers(int size, int board[MAX_SIZE][MAX_SIZE], int difficulty)
{
    //TODO
}

void save_game(int size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    //TODO
}

bool load_game(int* size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
    //TODO
    return false;
}
