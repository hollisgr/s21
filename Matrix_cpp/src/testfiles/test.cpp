#include "test.h"

TEST(accessorsTest, get_index1) {
  double n;
  S21Matrix test;
  n = test.getValue(1, 1);
  ASSERT_EQ(n, 0);
}

TEST(accessorsTest, set_index) {
  double n, m;
  m = 3.2222;
  S21Matrix test;
  test.setValue(1, 1, m);
  n = test.getValue(1, 1);
  ASSERT_EQ(n, m);
}

TEST(constructorTest, default_constructor) {
  S21Matrix test;
  ASSERT_EQ(test.getRows(), 3);
  ASSERT_EQ(test.getCols(), 3);
}

TEST(constructorTest, num_constructor) {
  S21Matrix test(5, 5);
  ASSERT_EQ(test.getRows(), 5);
  ASSERT_EQ(test.getCols(), 5);
}

TEST(constructorTest, copy_constructor) {
  S21Matrix test1(5, 5);
  S21Matrix test2(test1);
  ASSERT_EQ(test2.getRows(), 5);
  ASSERT_EQ(test2.getCols(), 5);
}

TEST(constructorTest, move_constructor) {
  S21Matrix test1(5, 5);
  S21Matrix test2(std::move(test1));
  ASSERT_EQ(test2.getRows(), 5);
  ASSERT_EQ(test2.getCols(), 5);
  ASSERT_EQ(test1.getRows(), 0);
  ASSERT_EQ(test1.getCols(), 0);
}

TEST(operationsTest, eq_matrix1) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  test1.setValue(1, 1, 1.33);
  test2.setValue(1, 1, 1.33);
  ASSERT_EQ(test1.EqMatrix(test2), true);
}

TEST(operationsTest, eq_matrix2) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  test1.setValue(1, 1, 1.333334);
  test2.setValue(1, 1, 1.333333);
  ASSERT_EQ(test1.EqMatrix(test2), false);
}

TEST(operationsTest, eq_matrix3) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  test1.setValue(1, 1, 1.3333334);
  test2.setValue(1, 1, 1.3333333);
  ASSERT_EQ(test1.EqMatrix(test2), true);
}

TEST(operationsTest, eq_matrix4) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  test1.setValue(1, 1, 1.3333334);
  test2.setValue(1, 1, 1.3333333);
  bool res = test1 == test2;
  ASSERT_EQ(res, true);
}

TEST(operationsTest, sum_matrix1) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 1);
  test2.setValue(1, 1, 1);
  result.setValue(1, 1, 2);
  test1.SumMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, sum_matrix2) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 1);
  test2.setValue(1, 1, 1);
  result.setValue(1, 1, 3);
  test1.SumMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), false);
}

TEST(operationsTest, sum_matrix3) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 10);
  test2.setValue(1, 1, 10);
  result.setValue(1, 1, 20);
  test1 += test2;
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, sum_matrix4) {
  S21Matrix test1(2, 2);
  S21Matrix test2(1, 1);
  EXPECT_THROW(test1.SumMatrix(test2), std::invalid_argument);
}

TEST(operationsTest, sum_matrix5) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix test3(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 10);
  test2.setValue(1, 1, 10);
  result.setValue(1, 1, 20);
  test3 = test1 + test2;
  ASSERT_EQ(test3.EqMatrix(result), true);
}

// TEST(operationsTest, sum_matrix5) {
//     S21Matrix test1(2, 2);
//     S21Matrix test2(2, 2);
//     S21Matrix test3(2, 2);
//     S21Matrix result(2, 2);
//     test1.setValue(1, 1, 1);
//     test2.setValue(1, 1, 1);
//     result.setValue(1, 1, 3);
//     test3 = test1 + test2;
//     ASSERT_EQ(test3.EqMatrix(result), 0);
// }

TEST(operationsTest, sub_matrix1) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 1);
  test2.setValue(1, 1, 1);
  result.setValue(1, 1, 0);
  test1.SubMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, sub_matrix2) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 1);
  test2.setValue(1, 1, 1);
  result.setValue(1, 1, 2);
  test1.SubMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), false);
}

TEST(operationsTest, sub_matrix3) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 15);
  test2.setValue(1, 1, 5);
  result.setValue(1, 1, 10);
  test1 -= test2;
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, sub_matrix4) {
  S21Matrix test1(2, 2);
  S21Matrix test2(1, 1);
  EXPECT_THROW(test1.SubMatrix(test2), std::invalid_argument);
}

TEST(operationsTest, sub_matrix5) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix test3(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 10);
  test2.setValue(1, 1, 10);
  result.setValue(1, 1, 0);
  test3 = test1 - test2;
  ASSERT_EQ(test3.EqMatrix(result), true);
}

TEST(operationsTest, mult_number1) {
  S21Matrix test1(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 2);
  result.setValue(1, 1, 4);
  test1.MulNumber(2);
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, mult_number2) {
  S21Matrix test1(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 2);
  result.setValue(1, 1, 5);
  test1.MulNumber(2);
  ASSERT_EQ(test1.EqMatrix(result), false);
}

TEST(operationsTest, mult_number3) {
  S21Matrix test1(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 2);
  result.setValue(1, 1, 4);
  test1 *= 2;
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, mult_number4) {
  S21Matrix test1(2, 2);
  S21Matrix test2(2, 2);
  S21Matrix result(2, 2);
  test1.setValue(1, 1, 2);
  result.setValue(1, 1, 4);
  test2 = test1 * 2;
  ASSERT_EQ(test2.EqMatrix(result), true);
}

TEST(operationsTest, mult_matrix1) {
  S21Matrix test1(3, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(3, 3);
  double test_matrix1[3][3];
  double test_matrix2[3][3];
  double test_result[3][3];
  test_matrix1[0][0] = 1;
  test_matrix1[0][1] = 2;
  test_matrix1[0][2] = 2;
  test_matrix1[1][0] = 1;
  test_matrix1[1][1] = 3;
  test_matrix1[1][2] = 2;
  test_matrix1[2][0] = 1;
  test_matrix1[2][1] = 1;
  test_matrix1[2][2] = 3;
  // matrix2
  test_matrix2[0][0] = 3;
  test_matrix2[0][1] = 3;
  test_matrix2[0][2] = 1;
  test_matrix2[1][0] = 2;
  test_matrix2[1][1] = 2;
  test_matrix2[1][2] = 1;
  test_matrix2[2][0] = 1;
  test_matrix2[2][1] = 3;
  test_matrix2[2][2] = 1;
  // matrix_test
  test_result[0][0] = 9;
  test_result[0][1] = 13;
  test_result[0][2] = 5;
  test_result[1][0] = 11;
  test_result[1][1] = 15;
  test_result[1][2] = 6;
  test_result[2][0] = 8;
  test_result[2][1] = 14;
  test_result[2][2] = 5;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      test1.setValue(i, j, test_matrix1[i][j]);
      test2.setValue(i, j, test_matrix2[i][j]);
      result.setValue(i, j, test_result[i][j]);
    }
  test1.MulMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, mult_matrix2) {
  S21Matrix test1(3, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(3, 3);
  double test_matrix1[3][3];
  double test_matrix2[3][3];
  double test_result[3][3];
  test_matrix1[0][0] = 1;
  test_matrix1[0][1] = 0;
  test_matrix1[0][2] = 2;
  test_matrix1[1][0] = 1;
  test_matrix1[1][1] = 3;
  test_matrix1[1][2] = 2;
  test_matrix1[2][0] = 1;
  test_matrix1[2][1] = 1;
  test_matrix1[2][2] = 3;
  // matrix2
  test_matrix2[0][0] = 3;
  test_matrix2[0][1] = 3;
  test_matrix2[0][2] = 1;
  test_matrix2[1][0] = 2;
  test_matrix2[1][1] = 2;
  test_matrix2[1][2] = 1;
  test_matrix2[2][0] = 1;
  test_matrix2[2][1] = 3;
  test_matrix2[2][2] = 1;
  // matrix_test
  test_result[0][0] = 9;
  test_result[0][1] = 13;
  test_result[0][2] = 5;
  test_result[1][0] = 11;
  test_result[1][1] = 15;
  test_result[1][2] = 6;
  test_result[2][0] = 8;
  test_result[2][1] = 14;
  test_result[2][2] = 5;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      test1.setValue(i, j, test_matrix1[i][j]);
      test2.setValue(i, j, test_matrix2[i][j]);
      result.setValue(i, j, test_result[i][j]);
    }
  test1.MulMatrix(test2);
  ASSERT_EQ(test1.EqMatrix(result), false);
}

TEST(operationsTest, mult_matrix3) {
  S21Matrix test1(3, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(3, 3);
  double test_matrix1[3][3];
  double test_matrix2[3][3];
  double test_result[3][3];
  test_matrix1[0][0] = 1;
  test_matrix1[0][1] = 2;
  test_matrix1[0][2] = 2;
  test_matrix1[1][0] = 1;
  test_matrix1[1][1] = 3;
  test_matrix1[1][2] = 2;
  test_matrix1[2][0] = 1;
  test_matrix1[2][1] = 1;
  test_matrix1[2][2] = 3;
  // matrix2
  test_matrix2[0][0] = 3;
  test_matrix2[0][1] = 3;
  test_matrix2[0][2] = 1;
  test_matrix2[1][0] = 2;
  test_matrix2[1][1] = 2;
  test_matrix2[1][2] = 1;
  test_matrix2[2][0] = 1;
  test_matrix2[2][1] = 3;
  test_matrix2[2][2] = 1;
  // matrix_test
  test_result[0][0] = 9;
  test_result[0][1] = 13;
  test_result[0][2] = 5;
  test_result[1][0] = 11;
  test_result[1][1] = 15;
  test_result[1][2] = 6;
  test_result[2][0] = 8;
  test_result[2][1] = 14;
  test_result[2][2] = 5;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      test1.setValue(i, j, test_matrix1[i][j]);
      test2.setValue(i, j, test_matrix2[i][j]);
      result.setValue(i, j, test_result[i][j]);
    }
  test1 *= test2;
  ASSERT_EQ(test1.EqMatrix(result), true);
}

TEST(operationsTest, mult_matrix4) {
  S21Matrix test1(2, 2);
  S21Matrix test2(1, 1);
  EXPECT_THROW(test1.MulMatrix(test2), std::invalid_argument);
}

TEST(operationsTest, mult_matrix5) {
  S21Matrix test1(3, 3);
  S21Matrix test2(3, 3);
  S21Matrix test3(3, 3);
  S21Matrix result(3, 3);
  double test_matrix1[3][3];
  double test_matrix2[3][3];
  double test_result[3][3];
  test_matrix1[0][0] = 1;
  test_matrix1[0][1] = 2;
  test_matrix1[0][2] = 2;
  test_matrix1[1][0] = 1;
  test_matrix1[1][1] = 3;
  test_matrix1[1][2] = 2;
  test_matrix1[2][0] = 1;
  test_matrix1[2][1] = 1;
  test_matrix1[2][2] = 3;
  // matrix2
  test_matrix2[0][0] = 3;
  test_matrix2[0][1] = 3;
  test_matrix2[0][2] = 1;
  test_matrix2[1][0] = 2;
  test_matrix2[1][1] = 2;
  test_matrix2[1][2] = 1;
  test_matrix2[2][0] = 1;
  test_matrix2[2][1] = 3;
  test_matrix2[2][2] = 1;
  // matrix_test
  test_result[0][0] = 9;
  test_result[0][1] = 13;
  test_result[0][2] = 5;
  test_result[1][0] = 11;
  test_result[1][1] = 15;
  test_result[1][2] = 6;
  test_result[2][0] = 8;
  test_result[2][1] = 14;
  test_result[2][2] = 5;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      test1.setValue(i, j, test_matrix1[i][j]);
      test2.setValue(i, j, test_matrix2[i][j]);
      result.setValue(i, j, test_result[i][j]);
    }
  test3 = test1 * test2;
  ASSERT_EQ(test3.EqMatrix(result), true);
}

TEST(operationsTest, getValue1) {
  double num = 0;
  S21Matrix test1(2, 2);
  num = test1.getValue(1, 1);
  ASSERT_EQ(num, 0);
}

TEST(operationsTest, getValue2) {
  S21Matrix test1(2, 2);
  EXPECT_THROW(test1.getValue(3, 2), std::invalid_argument);
}

TEST(operationsTest, getValue3) {
  S21Matrix test1(2, 2);
  EXPECT_THROW(test1.getValue(2, 3), std::invalid_argument);
}

TEST(operationsTest, getValue4) {
  S21Matrix test1(2, 2);
  EXPECT_THROW(test1.getValue(3, 3), std::invalid_argument);
}

TEST(operationsTest, setValue1) {
  double num = 1;
  S21Matrix test1(2, 2);
  test1.setValue(1, 1, num);
  ASSERT_EQ(test1.getValue(1, 1), num);
}

TEST(operationsTest, setValue2) {
  S21Matrix test1(2, 2);
  EXPECT_THROW(test1.setValue(3, 3, 3), std::invalid_argument);
}

TEST(operationsTest, setRows1) {
  int new_rows = 5;
  S21Matrix test1(4, 4);
  test1.setRows(new_rows);
  ASSERT_EQ(test1.getRows(), new_rows);
}

TEST(operationsTest, setCols1) {
  int new_cols = 5;
  S21Matrix test1(4, 4);
  test1.setCols(new_cols);
  ASSERT_EQ(test1.getCols(), new_cols);
}

TEST(operationsTest, Determinant1) {
  S21Matrix test1(3, 3);
  double determinant = 0;
  determinant = test1.Determinant();
  ASSERT_EQ(determinant, 0);
}

TEST(operationsTest, Determinant2) {
  S21Matrix test1(3, 3);
  double matrix[3][3];
  double determinant = 0;
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  matrix[1][0] = 4;
  matrix[1][1] = 5;
  matrix[1][2] = 6;
  matrix[2][0] = 7;
  matrix[2][1] = 8;
  matrix[2][2] = 9;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) test1.setValue(i, j, matrix[i][j]);
  determinant = test1.Determinant();
  ASSERT_EQ(determinant, 0);
}

TEST(operationsTest, Determinant3) {
  S21Matrix test1(3, 3);
  double matrix[3][3];
  double determinant = 0;
  matrix[0][0] = 0;
  matrix[0][1] = 2;
  matrix[0][2] = 4;
  matrix[1][0] = 1;
  matrix[1][1] = 3;
  matrix[1][2] = 3;
  matrix[2][0] = 2;
  matrix[2][1] = 3;
  matrix[2][2] = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) test1.setValue(i, j, matrix[i][j]);
  determinant = test1.Determinant();
  ASSERT_EQ(determinant, -2);
}

TEST(operationsTest, Determinant4) {
  S21Matrix test1(1, 1);
  double determinant = 0;
  determinant = test1.Determinant();
  ASSERT_EQ(determinant, 0);
}

TEST(operationsTest, Determinant5) {
  S21Matrix test1(2, 3);
  EXPECT_THROW(test1.Determinant(), std::invalid_argument);
}

TEST(operationsTest, CalcComplements1) {
  S21Matrix test1(3, 3);
  double val = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) test1.setValue(i, j, ++val);
  double check_value[9] = {-3, 6, -3, 6, -12, 6, -3, 6, -3};
  S21Matrix res = test1.CalcComplements();
  int kl = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      ASSERT_EQ(res.getValue(i, j), check_value[kl]);
      kl++;
    }
}

TEST(operationsTest, CalcComplements2) {
  S21Matrix test1(1, 1);
  double val = 0;
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++) test1.setValue(i, j, ++val);
  double check_val[1] = {1};
  S21Matrix res = test1.CalcComplements();
  int kl = 0;
  for (int i = 0; i < 1; i++)
    for (int j = 0; j < 1; j++) {
      ASSERT_EQ(res.getValue(i, j), check_val[kl]);
      kl++;
    }
}

TEST(operationsTest, CalcComplements3) {
  S21Matrix test1(2, 3);
  EXPECT_THROW(test1.CalcComplements(), std::invalid_argument);
}

TEST(operationsTest, index) {
  S21Matrix test1(2, 2);
  test1.setValue(1, 1, 2);
  double result = test1(1, 1);
  ASSERT_EQ(result, 2);
}

TEST(operationsTest, inverseMatrix1) {
  S21Matrix test1(1, 1);
  test1.setValue(0, 0, 4);
  S21Matrix res = test1.InverseMatrix();
  ASSERT_EQ(res(0, 0), 0.25);
}

TEST(operationsTest, inverseMatrix2) {
  S21Matrix test1(0, 0);
  EXPECT_THROW(test1.InverseMatrix(), std::invalid_argument);
}

TEST(operationsTest, inverseMatrix3) {
  S21Matrix test1(2, 3);
  EXPECT_THROW(test1.InverseMatrix(), std::invalid_argument);
}

TEST(operationsTest, inverseMatrix4) {
  S21Matrix test1(3, 3);
  EXPECT_THROW(test1.InverseMatrix(), std::invalid_argument);
}

TEST(operationsTest, inverseMatrix5) {
  S21Matrix test1(3, 3);
  S21Matrix result(3, 3);
  double matrix[3][3];
  double matrix_result[3][3];
  matrix[0][0] = 2;
  matrix[0][1] = 5;
  matrix[0][2] = 7;
  matrix[1][0] = 6;
  matrix[1][1] = 3;
  matrix[1][2] = 4;
  matrix[2][0] = 5;
  matrix[2][1] = -2;
  matrix[2][2] = -3;

  matrix_result[0][0] = 1;
  matrix_result[0][1] = -1;
  matrix_result[0][2] = 1;
  matrix_result[1][0] = -38;
  matrix_result[1][1] = 41;
  matrix_result[1][2] = -34;
  matrix_result[2][0] = 27;
  matrix_result[2][1] = -29;
  matrix_result[2][2] = 24;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      test1.setValue(i, j, matrix[i][j]);
      result.setValue(i, j, matrix_result[i][j]);
    }
  S21Matrix test2 = test1.InverseMatrix();
  ASSERT_EQ(result.EqMatrix(test2), true);
}

// TEST(operationsTest, transpose1) {
//     S21Matrix test1(2, 3);
//     S21Matrix test2 = test1.Transpose();
//     S21Matrix result(3, 2);
//     result.setValue(1, 1, 1);
//     ASSERT_EQ(result.EqMatrix(test2), 0);
// }

// TEST(operationsTest, transpose2) {
//     S21Matrix test1(3, 2);
//     S21Matrix result(2, 3);
//     double matrix1[3][2];
//     double matrix2[2][3];
//     // matrix1
//     matrix1[0][0] = 1;
//     matrix1[0][1] = 4;
//     matrix1[1][0] = 2;
//     matrix1[1][1] = 5;
//     matrix1[2][0] = 3;
//     matrix1[2][1] = 6;
//     // matrix_test
//     matrix2[0][0] = 1;
//     matrix2[0][1] = 2;
//     matrix2[0][2] = 3;
//     matrix2[1][0] = 4;
//     matrix2[1][1] = 5;
//     matrix2[1][2] = 6;
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 2; j++)
//             test1.setValue(i, j, matrix1[i][j]);
//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < 3; j++)
//             result.setValue(i, j, matrix2[i][j]);
//     S21Matrix test2 = test1.Transpose();
//     ASSERT_EQ(result.EqMatrix(test2), 1);
// }

// TEST(operationsTest, transpose3) {
//     S21Matrix test1(3, 2);
//     S21Matrix result(2, 3);
//     double matrix1[3][2];
//     double matrix2[2][3];
//     // matrix1
//     matrix1[0][0] = 1;
//     matrix1[0][1] = 4;
//     matrix1[1][0] = 2;
//     matrix1[1][1] = 5;
//     matrix1[2][0] = 3;
//     matrix1[2][1] = 7;
//     // matrix_test
//     matrix2[0][0] = 1;
//     matrix2[0][1] = 2;
//     matrix2[0][2] = 3;
//     matrix2[1][0] = 4;
//     matrix2[1][1] = 5;
//     matrix2[1][2] = 6;
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 2; j++)
//             test1.setValue(i, j, matrix1[i][j]);
//     for (int i = 0; i < 2; i++)
//         for (int j = 0; j < 3; j++)
//             result.setValue(i, j, matrix2[i][j]);
//     S21Matrix test2 = test1.Transpose();
//     ASSERT_EQ(result.EqMatrix(test2), 0);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
