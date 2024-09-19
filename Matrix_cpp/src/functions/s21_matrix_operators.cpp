#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.SumMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.SubMatrix(other);
  return temp;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix temp(*this);
  temp.MulNumber(num);
  return temp;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix temp(*this);
  temp.MulMatrix(other);
  return temp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(double num) {
  this->MulNumber(num);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  this->deleteMatrix();
  this->createMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] = other.matrix_[i][j];
  return *this;
}

double S21Matrix::operator()(int i, int j) {
  double value = 0;
  value = this->getValue(i, j);
  return value;
}