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
     FILE* file = fopen(filename, "w");
    if (!file)
    {
        printf("Failed to open file for saving.\n");
        return;
    }

    fprintf(file, "%d\n", size);

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            fprintf(file, "%d ", board[row][col]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Game saved to %s\n", filename);
}

bool load_game(int* size, int board[MAX_SIZE][MAX_SIZE], const char* filename)
{
      FILE* file = fopen(filename, "r");
    if (!file)
    {
        printf("Failed to open file for loading.\n");
        return false;
    }

    if (fscanf(file, "%d", size) != 1)
    {
        printf("Invalid file format.\n");
        fclose(file);
        return false;
    }

    if (*size > MAX_SIZE)
    {
        printf("Loaded board size too large.\n");
        fclose(file);
        return false;
    }

    for (int row = 0; row < *size; row++)
    {
        for (int col = 0; col < *size; col++)
        {
            if (fscanf(file, "%d", &board[row][col]) != 1)
            {
                printf("Invalid board data in file.\n");
                fclose(file);
                return false;
            }
        }
    }

    fclose(file);
    printf("Game loaded from %s\n", filename);
    return true;

}

void make_move(int size, int board[MAX_SIZE][MAX_SIZE])
{
    int row, col, value;
    printf("Enter your move (row col value), value = 0 to delete, -1 to cancel: ");
    if (scanf("%d", &row) != 1 || row == -1) return;
    if (scanf("%d %d", &col, &value) != 2) return;

    if (row < 0 || row >= size || col < 0 || col >= size)
    {
        printf("Invalid coordinates.\n");
        return;
    }

    if (value == 0)
    {
        board[row][col] = 0;
        printf("Value deleted.\n");
        return;
    }

    if (value < 1 || value > size)
    {
        printf("Invalid value.\n");
        return;
    }

    if (!is_valid(size, board, row, col, value))
    {
        printf("Move violates Sudoku rules.\n");
        return;
    }

    board[row][col] = value;
    printf("Move applied.\n");
}

void show_hints(int size, int board[MAX_SIZE][MAX_SIZE], int row, int col)
{
    printf("Hints for cell [%d][%d]: ", row, col);
    for (int val = 1; val <= size; val++)
    {
        if (is_valid(size, board, row, col, val))
        {
            printf("%d ", val);
        }
    }
    printf("\n");
}

void play_game(int size, int board[MAX_SIZE][MAX_SIZE]) {
    int choice;
    char filename[100];
    time_t start_time = time(NULL);

    while (1) {
        printf("\n--- Game Menu ---\n");
        printf("1. Make Move\n");
        printf("2. Show Board\n");
        printf("3. Show Hints\n");
        printf("4. Save Game\n");
        printf("5. Show Time\n");
        printf("6. Back to Main Menu\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                make_move(size, board);
                break;
            case 2:
                print_board(size, board);
                break;
            case 3:
                printf("Enter cell (row col): ");
                int r, c;
                scanf("%d %d", &r, &c);
                if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == 0)
                    show_hints(size, board, r, c);
                else
                    printf("Invalid cell or not empty.\n");
                break;
            case 4:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_game(size, board, filename);
                break;
            case 5:
                printf("Elapsed time: %ld seconds\n", time(NULL) - start_time);
                break;
            case 6:
                return;
            default:
                printf("Invalid option.\n");
        }
    }
}

void main_menu()
{
    int board[MAX_SIZE][MAX_SIZE];
    int size = 9;
    int difficulty = 2;
    int choice;
    char filename[100];

    srand(time(NULL));

    time_t start_time = time(NULL);

    while (1)
    {
        printf("\nSudoku Menu\n");
        printf("1. New Game\n");
        printf("2. Load Game\n");
        printf("3. Save Game\n");
        printf("4. Make Move\n");
        printf("5. Show Board\n");
        printf("6. Quit\n");
        printf("7. Show Hints\n");
        printf("8. Show Time\n");
        printf("Choose option: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice)
        {
            case 1:
                printf("Select size (4 / 9 / 16): ");
                scanf("%d", &size);
                if (size != 4 && size != 9 && size != 16) size = 9;

                printf("Select difficulty (1 = Easy, 2 = Medium, 3 = Hard): ");
                scanf("%d", &difficulty);
                clear_board(size, board);
                fill_board(size, board);
                remove_numbers(size, board, difficulty);
                play_game(size, board);
                break;

            case 2:
                printf("Enter filename to load: ");
                scanf("%s", filename);
                load_game(&size, board, filename);
                break;

            case 3:
                printf("Enter filename to save: ");
                scanf("%s", filename);
                save_game(size, board, filename);
                break;

            case 4:
                make_move(size, board);
                break;

            case 5:
                print_board(size, board);
                break;

            case 6:
                printf("Goodbye!\n");
                return;

            case 7:
                printf("Enter cell (row col): ");
                int r, c;
                scanf("%d %d", &r, &c);
                if (r >= 0 && r < size && c >= 0 && c < size && board[r][c] == 0)
                    show_hints(size, board, r, c);
                else
                    printf("Invalid cell or not empty.\n");
                break;

            case 8:
                printf("Elapsed time: %ld seconds\n", time(NULL) - start_time);
                break;

            default:
                printf("Invalid option.\n");
        }
    }
}
