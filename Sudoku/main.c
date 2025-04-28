#include <stdio.h>
#include "sudoku.h"

int main()
{
    int size = 9;
    int board[MAX_SIZE][MAX_SIZE];

    clear_board(size, board);
    print_board(size, board);

    return 0;
}
