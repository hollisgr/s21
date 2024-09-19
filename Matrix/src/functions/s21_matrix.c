#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0)
    return S21_INCORRECT_MATRIX;
  else {
    result->matrix = (double **)calloc(
        (rows * sizeof(double *)) + (columns * rows * sizeof(double)), 1);
    result->matrix[0] = (double *)(result->matrix + rows);
    for (int i = 1; i < rows; i++)
      result->matrix[i] = result->matrix[0] + columns * i;
    result->rows = rows;
    result->columns = columns;
  }
  return S21_RETURN_OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (A) {
    free(A->matrix);
    A->matrix = NULL;
  }
  A->rows = 0;
  A->columns = 0;
}