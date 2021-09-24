#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int **get_matrix(char *, int *, int *);
void free_matrix(int **, int);
bool is_sparse(int **, int, int, int *);
int **make_sparse(int **, int, int, int);
void display_sparse(int **, int);

int main(void)
{
    printf("\n---------- 3 TUPLE REPRESENTATION OF SPARSE MATRIX ----------\n");
    printf("-------------------------------------------------------------\n\n");

    int rows = 0, cols = 0;
    int **matrix = get_matrix(
        "Enter the matrix. Hit CTRL+D to exit.\n"
        "Rows start at every newline.\n"
        "Columns are seperated by a space.\n",
        &rows, &cols
    );

    int non_zeroes = 0;
    if (is_sparse(matrix, rows, cols, &non_zeroes)) {
        int **sparse_matrix = make_sparse(matrix, rows, cols, non_zeroes);
        display_sparse(sparse_matrix, non_zeroes);
        free_matrix(sparse_matrix, non_zeroes);
    }
    else
        printf("\nThe given matrix is not sparse.\n\n");

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

bool is_sparse(int **matrix, int row, int col, int *non_zeroes)
{
    if (matrix == NULL) return false;
    
    int zeroes = 0;
    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            if (matrix[i][j] == 0) zeroes++;

    *non_zeroes = row * col - zeroes;
    return zeroes >= *non_zeroes;
}

int **make_sparse(int **matrix, int row, int col, int non_zeroes)
{
    int **sparse = malloc( non_zeroes * sizeof(int *) );
    for (int i = 0, s_row = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] != 0) {
                sparse[s_row] = malloc( 3 * sizeof(int) );
                sparse[s_row][0] = i + 1;
                sparse[s_row][1] = j + 1;
                sparse[s_row][2] = matrix[i][j];
                ++s_row;
            }
        }
    }
    return sparse;
}

void display_sparse(int **sparse, int non_zeroes)
{
    printf("\nRow\t\tColumn\t\tValue\n");
    for (int i = 0; i < non_zeroes; ++i)
        printf("%d\t\t%d\t\t%d\n", 
                sparse[i][0], sparse[i][1], sparse[i][2]);
    printf("\n");
}