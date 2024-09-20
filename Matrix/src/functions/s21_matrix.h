#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 10e-7

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

typedef enum s21_return {
  S21_RETURN_OK = 0,
  S21_INCORRECT_MATRIX = 1,
  S21_ARITHMETIC_ERROR = 2
} s21_return;

// common functions
int s21_validation_matrix(matrix_t *matrix);
void s21_record_determinant(matrix_t *determinant, matrix_t *A, int minor_row,
                            int minor_col);
void s21_algebraic_complements(matrix_t *A, matrix_t *result);

// task functions

// create/remove
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// arithmetics
int s21_arithmetic_matrix(matrix_t *A, matrix_t *B, matrix_t *result,
                          char operation);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// other
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif