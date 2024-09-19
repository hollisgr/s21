#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  createMatrix(3, 3);
}

S21Matrix::S21Matrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  createMatrix(rows, cols);
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  this->createMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++)
    for (int j = 0; j < this->cols_; j++)
      this->matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { this->deleteMatrix(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  double n = 0;
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) {
      n = fabs(this->matrix_[i][j] - other.matrix_[i][j]);
      if (n > EPS) return false;
    }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  check_matrix_size(other);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  this->check_matrix_size(other);
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) this->matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) this->matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  check_matrix_cols(other);
  S21Matrix temp(rows_, other.cols_);
  for (int i = 0; i < temp.rows_; i++)
    for (int j = 0; j < temp.cols_; j++)
      for (int k = 0; k < this->cols_; k++)
        temp.matrix_[i][j] =
            temp.matrix_[i][j] + (this->matrix_[i][k] * other.matrix_[k][j]);
  this->copyMatrix(temp);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix temp(this->cols_, this->rows_);
  for (int i = 0; i < temp.rows_; i++)
    for (int j = 0; j < temp.cols_; j++)
      temp.matrix_[i][j] = this->matrix_[j][i];
  return temp;
}

double S21Matrix::Determinant() {
  if (this->rows_ != this->cols_) throw std::invalid_argument("Invalid matrix");
  double result = 0;
  if (this->rows_ == 1) {
    result = this->matrix_[0][0];
  } else if (this->rows_ == 2) {
    result = this->matrix_[0][0] * this->matrix_[1][1] -
             this->matrix_[1][0] * this->matrix_[0][1];
  } else if (this->rows_ > 2) {
    for (int i = 0; i < this->cols_; i++) {
      S21Matrix Minor = this->Minor(0, i);
      if (Minor.matrix_ != nullptr) {
        int sign = i % 2 == 0 ? 1 : -1;
        result += sign * this->matrix_[0][i] * Minor.Determinant();
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::Minor(int row, int column) {
  S21Matrix result(this->rows_ - 1, this->cols_ - 1);
  int minor_row = 0;
  for (int i = 0; i < this->rows_; i++) {
    if (i != row) {
      int minor_column = 0;
      for (int j = 0; j < this->cols_; j++) {
        if (j != column) {
          result.matrix_[minor_row][minor_column] = this->matrix_[i][j];
          minor_column++;
        }
      }
      minor_row++;
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (this->rows_ != this->cols_) throw std::invalid_argument("Invalid matrix");
  S21Matrix result(this->rows_, this->cols_);
  if (this->rows_ == 1)
    result.matrix_[0][0] = 1;
  else {
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        S21Matrix Minor = this->Minor(i, j);
        if (Minor.matrix_ != nullptr) {
          int sign = (i + j) % 2 == 0 ? 1 : -1;
          double det = Minor.Determinant();
          result.matrix_[i][j] = sign * det;
        }
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (this->rows_ <= 0 || this->cols_ <= 0)
    throw std::invalid_argument("Invalid matrix");
  if (this->rows_ != this->cols_) throw std::invalid_argument("Invalid matrix");
  double det = this->Determinant();
  if (det == 0) throw std::invalid_argument("Invalid determinant");
  S21Matrix result;
  if (this->rows_ == 1) {
    result = S21Matrix(1, 1);
    result.matrix_[0][0] = 1 / this->matrix_[0][0];
  } else {
    result = this->CalcComplements();
    result = result.Transpose();
    for (int i = 0; i < result.rows_; i++)
      for (int j = 0; j < result.cols_; j++) result.matrix_[i][j] /= det;
  }
  return result;
}