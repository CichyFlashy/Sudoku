
#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdbool.h>

#define MAX_SIZE 16

void clear_board(int size, int board[MAX_SIZE][MAX_SIZE]);
void print_board(int size, int board[MAX_SIZE][MAX_SIZE]);
bool is_valid(int size, int board[MAX_SIZE][MAX_SIZE], int row, int col, int num);
bool fill_board(int size, int board[MAX_SIZE][MAX_SIZE]);
void remove_numbers(int size, int board[MAX_SIZE][MAX_SIZE], int difficulty);
void save_game(int size, int board[MAX_SIZE][MAX_SIZE], const char* filename);
void load_game(int* size, int board[MAX_SIZE][MAX_SIZE], const char* filename);
void make_move(int size, int board[MAX_SIZE][MAX_SIZE]);
void main_menu(void);
#endif // SUDOKU_H
