#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int return_value = SUCCESS;
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B)) return FAILURE;
  if (A->rows != B->rows || A->columns != B->columns)
    return FAILURE;
  else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          return_value = FAILURE;
          break;
        }
      }
    }
  }
  return return_value;
}

int s21_arithmetic_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                          char operation) {
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B))
    return S21_INCORRECT_MATRIX;
  else if (A->rows != B->rows || A->columns != B->columns)
    return S21_ARITHMETIC_ERROR;
  else {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (operation == '+')
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        if (operation == '-')
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return S21_RETURN_OK;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  char operation = '+';
  return s21_arithmetic_matrix(A, B, result, operation);
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  char operation = '-';
  return s21_arithmetic_matrix(A, B, result, operation);
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_validation_matrix(A)) return S21_INCORRECT_MATRIX;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return S21_RETURN_OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_validation_matrix(A) || !s21_validation_matrix(B))
    return S21_INCORRECT_MATRIX;
  else {
    s21_create_matrix(A->rows, B->columns, result);
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] =
              result->matrix[i][j] + (A->matrix[i][k] * B->matrix[k][j]);
        }
      }
    }
  }
  return S21_RETURN_OK;
}
