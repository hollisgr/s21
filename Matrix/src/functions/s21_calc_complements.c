#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_validation_matrix(A)) return S21_INCORRECT_MATRIX;
  if (A->rows != A->columns) return S21_ARITHMETIC_ERROR;
  matrix_t determinant;
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows > 1)
    s21_create_matrix(A->columns - 1, A->rows - 1, &determinant);
  else
    result->matrix[0][0] = 1.0;
  for (int minor_row = 0; minor_row < A->rows && A->rows > 1; minor_row++) {
    for (int minor_col = 0; minor_col < A->columns; minor_col++) {
      s21_record_determinant(&determinant, A, minor_row, minor_col);
      s21_determinant(&determinant, &result->matrix[minor_row][minor_col]);
    }
  }
  if (A->rows > 1) {
    s21_remove_matrix(&determinant);
    s21_algebraic_complements(A, result);
  }
  return S21_RETURN_OK;
}