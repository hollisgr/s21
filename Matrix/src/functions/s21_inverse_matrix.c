#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_validation_matrix(A)) return S21_INCORRECT_MATRIX;
  double determinant = 0.0;
  if (A->rows != A->columns) return S21_ARITHMETIC_ERROR;
  s21_determinant(A, &determinant);
  if (determinant) {
    matrix_t complements, transpose;
    s21_calc_complements(A, &complements);
    s21_transpose(&complements, &transpose);
    determinant = 1 / determinant;
    s21_mult_number(&transpose, determinant, result);
    s21_remove_matrix(&complements);
    s21_remove_matrix(&transpose);
  } else
    return S21_ARITHMETIC_ERROR;
  return S21_RETURN_OK;
}