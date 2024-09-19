#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (!s21_validation_matrix(A)) return S21_INCORRECT_MATRIX;
  if (A->rows != A->columns) return S21_ARITHMETIC_ERROR;
  int not_zero = 0, all_zero = 1, sign = 1;
  double *tmp = NULL;
  *result = 1.0;
  matrix_t temp;
  s21_create_matrix(A->columns, A->rows, &temp);
  for (int i = 0; i < temp.rows; i++) {
    for (int j = 0; j < temp.columns; j++) {
      temp.matrix[i][j] = A->matrix[i][j];
    }
  }
  for (int rows = 0; rows < temp.rows - 1; rows++) {
    for (not_zero = rows, all_zero = 1; not_zero < temp.rows; not_zero++) {
      if (temp.matrix[not_zero][rows]) {
        tmp = temp.matrix[not_zero];
        all_zero = 0;
        break;
      }
    }
    if (temp.matrix[rows][rows] == 0.0 && tmp) {
      temp.matrix[not_zero] = temp.matrix[rows];
      temp.matrix[rows] = tmp;
      sign = -sign;
    }
    if (all_zero)
      *result = 0.0;
    else {
      for (int m = rows + 1; m < temp.rows; m++) {
        double tmp = temp.matrix[m][rows] / temp.matrix[rows][rows];
        for (int n = rows; n < temp.columns; n++)
          temp.matrix[m][n] = temp.matrix[m][n] - temp.matrix[rows][n] * tmp;
      }
    }
  }
  for (int k = 0; k < A->rows; k++) *result = *result * temp.matrix[k][k];
  *result = *result * sign;
  s21_remove_matrix(&temp);
  return S21_RETURN_OK;
}