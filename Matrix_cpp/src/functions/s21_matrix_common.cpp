#include "s21_matrix_oop.h"

void S21Matrix::check_matrix_size(const S21Matrix& other) {
  if (other.rows_ != this->rows_ || other.cols_ != other.rows_)
    throw std::invalid_argument("DIFFERENT SIZE");
}

void S21Matrix::check_matrix_cols(const S21Matrix& other) {
  if (other.cols_ != this->cols_) throw std::invalid_argument("DIFFERENT COLS");
}

void S21Matrix::check_matrix_index(int i, int j) {
  if (i > rows_ || j > cols_)
    throw std::invalid_argument("INDEX IS OUT OF RANGE");
}

void S21Matrix::createMatrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;
  this->matrix_ = new double*[this->rows_]();
  for (int i = 0; i < this->rows_; i++)
    this->matrix_[i] = new double[this->cols_]();
}

void S21Matrix::deleteMatrix() {
  for (int i = 0; i < this->rows_; i++) delete[] this->matrix_[i];
  delete[] matrix_;
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

void S21Matrix::copyMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = other.matrix_[i][j];
}

int S21Matrix::getRows() { return this->rows_; }

int S21Matrix::getCols() { return this->cols_; }

void S21Matrix::setRows(int rows) {
  if (this->rows_ != rows) {
    S21Matrix temp(rows, this->cols_);
    for (int i = 0; i < std::min(this->rows_, rows); i++)
      for (int j = 0; j < temp.cols_; j++)
        temp.matrix_[i][j] = this->matrix_[i][j];
    *this = temp;
  }
}

void S21Matrix::setCols(int cols) {
  if (this->cols_ != cols) {
    S21Matrix temp(this->rows_, cols);
    for (int i = 0; i < rows_; i++)
      for (int j = 0; j < std::min(this->cols_, cols); j++)
        temp.matrix_[i][j] = this->matrix_[i][j];
    *this = temp;
  }
}

double S21Matrix::getValue(int i, int j) {
  double num = 0;
  check_matrix_index(i, j);
  num = matrix_[i][j];
  return num;
}

void S21Matrix::setValue(int i, int j, double num) {
  check_matrix_index(i, j);
  matrix_[i][j] = num;
}