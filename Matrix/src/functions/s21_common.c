#include "s21_matrix.h"

int s21_validation_matrix(matrix_t *matrix) {
  if (matrix->rows <= 0 || matrix->columns <= 0) return FAILURE;
  return SUCCESS;
}

void s21_algebraic_complements(matrix_t *A, matrix_t *result) {
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if ((n + m) % 2) result->matrix[m][n] = result->matrix[m][n] * -1;
    }
  }
}

void s21_record_determinant(matrix_t *determinant, matrix_t *A, int minor_row,
                            int minor_col) {
  for (int src_row = 0, det_rows = 0; src_row < A->rows; src_row++) {
    for (int src_col = 0, det_col = 0; src_col < A->columns; src_col++) {
      if (src_row != minor_row && src_col != minor_col) {
        determinant->matrix[det_rows][det_col] = A->matrix[src_row][src_col];
        det_col++;
        if (det_col == determinant->columns) {
          det_rows++;
          det_col = 0;
        }
      }
    }
  }
}

// int s21_zero_matrix(matrix_t *result) {
//   if (!result || s21_validation_matrix(result) == FAILURE)
//     return S21_INCORRECT_MATRIX;
//   else
//     for (int i = 0; i < result->rows; i++) {
//       for (int j = 0; j < result->columns; j++) result->matrix[i][j] = 0;
//     }
//   return S21_RETURN_OK;
// }

// void s21_print_matrix(matrix_t *matrix) {
//   for (int i = 0; i < matrix->rows; i++) {
//     for (int j = 0; j < matrix->columns; j++)
//       printf("%lf ", matrix->matrix[i][j]);
//     printf("\n");
//   }
// }