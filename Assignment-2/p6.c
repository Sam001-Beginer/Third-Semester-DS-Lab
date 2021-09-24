#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int **get_matrix(char *, int *, int *);
void free_matrix(int **, int);
bool is_sparse(int **, int, int);

int main(void)
{
    printf("\n---------- SPARSE MATRIX ----------\n");
    printf("-----------------------------------\n\n");

    int rows = 0, cols = 0;
    int **matrix = get_matrix(
        "Enter the matrix. Hit CTRL+D to exit.\n"
        "Rows start at every newline.\n"
        "Columns are seperated by a space.\n",
        &rows, &cols
    );

    printf("\nMatrix is sparse? %s\n\n", is_sparse(matrix, rows, cols) ? "Yes" : "No");

    free_matrix(matrix, rows);
    return 0;
}

int **get_matrix(char *label, int *row, int *col)
{
    // Display label
    printf("%s", label);

    int **matrix = NULL;
    for (int c; (c = getc(stdin)) != EOF; ++(*row))
    {
        ungetc(c, stdin);
        matrix = realloc(matrix, (*row + 1) * sizeof(int *));
        *col = 0;
        // Loop through all the lines (rows)
        for (; (c = getc(stdin)) != '\n' && c != EOF; ++(*col))
        {
            ungetc(c, stdin);
            matrix[*row] = realloc(matrix[*row], (*col + 1) * sizeof(int));
            int pos = 0;
            // Loop through all the digits of the number and add them
            // to the matrix at i-th row and j-th column
            while ((c = getc(stdin)) != ' ' && c != '\n' && c != EOF)
            {
                if (c >= '0' && c <= '9')
                {
                    matrix[*row][*col] = pow(10, pos) * matrix[*row][*col] + (c - '0');
                    ++pos;
                }
            }
            // Return the accidentally read 
            // newline character to STDIN
            if (c == '\n') ungetc(c, stdin);
        }
    }
    return matrix;
}

void free_matrix(int **matrix, int row)
{
    // Loop through all the pointers and free them
    for (int i = 0; i < row; ++i)
        free(matrix[i]);
    free(matrix);
}

bool is_sparse(int **matrix, int row, int col)
{
    if (matrix == NULL) return false;
    
    int zeroes = 0;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (matrix[i][j] == 0) zeroes++;

    return zeroes >= row * col - zeroes;
}