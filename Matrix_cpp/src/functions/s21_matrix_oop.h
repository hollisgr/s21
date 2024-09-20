#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <math.h>

#include <iostream>

#define EPS 1e-7

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  S21Matrix operator*(double num);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix& operator*=(double num);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  double operator()(int i, int j);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  double Determinant();
  S21Matrix Minor(int row, int column);

  void createMatrix(int rows, int cols);
  void copyMatrix(const S21Matrix& other);
  void deleteMatrix();

  double getValue(int i, int j);
  void setValue(int i, int j, double num);

  int getRows();
  int getCols();
  void setRows(int rows);
  void setCols(int cols);

  void check_matrix_size(const S21Matrix& other);
  void check_matrix_cols(const S21Matrix& other);
  void check_matrix_index(int i, int j);
};

#endif