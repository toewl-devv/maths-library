#include "maths/matrix.hpp"
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;

namespace maths {

    // Initialisation
    Matrix::Matrix(int m, int n)
        : rows(m), columns(n),
        values(m, vector<double>(n, 0.0))
        {}

    Matrix::Matrix(vector<vector<double>> data)
        : values(data),
        rows(data.size())
        {
            if (data.size() == 0) {
                columns = 0;
            } else {
                columns = data[0].size();
            }
        }


    //Whole-matrix operations
    Matrix Matrix::transpose() const {
        Matrix transposed_matrix = Matrix(columns, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                transposed_matrix.values[j][i] = values[i][j];
            }
        }
        return transposed_matrix;
    }

    double Matrix::det() const { 
        if (rows != columns) {
            throw std::runtime_error("can only find the determinant of square matrices");
        }
        if (rows == 2) {
            return values[0][0] * values[1][1] - values[0][1] * values [1][0];
        }
        double det(0);
        for (int i = 0; i < columns; i++) {
            Matrix nextmatr = Matrix(rows - 1, columns - 1);
            for (int j = 0; j < columns - 1; j++) {
                // check if j >= i if so add one
                int current_column = (j >= i) ? j+1 : j;
                // add current column to the new matrix
                for (int row = 0; row < rows - 1; row++) {
                    nextmatr.values[row][j] = values[row+1][current_column];
                }
            }
            det += ((i % 2 == 0) * 2 - 1) * values[0][i] * nextmatr.det();
        }
        return det;
    }

    void Matrix::swap(int r1, int r2) {
        if (r1 < 1 || r2 < 1) {
            throw std::runtime_error("only non-negative row numbers allowed");
        }
        if (r1 > rows || r2 > rows) {
            throw std::runtime_error("rows numbers must be between 1 and number of rows");
        }
        vector<double> temp = values[r1 - 1];
        values[r1 - 1] = values[r2 - 1];
        values[r2 - 1] = temp;
    }


    //Operations
    Matrix Matrix::operator+(const Matrix &m) const {
        if (rows != m.rows || columns != m.columns) {
            throw std::runtime_error("can only add matrices of the same size");
        }

        vector<vector<double>> newmatrix = vector<vector<double>>(rows, vector<double>(columns, 0.0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix[i][j] = values[i][j] + m.values[i][j];
            }
        }
        return Matrix(newmatrix);
    }

    Matrix Matrix::operator-(const Matrix &m) const {
        if (rows != m.rows || columns != m.columns) {
            throw std::runtime_error("can only subtract matrices of the same size");
        }

        vector<vector<double>> newmatrix = vector<vector<double>>(rows, vector<double>(columns, 0.0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix[i][j] = values[i][j] - m.values[i][j];
            }
        }
        return Matrix(newmatrix);
    }

    Matrix Matrix::operator*(const Matrix &m) const {
        if (columns != m.rows) {
            throw std::runtime_error("can only multiply r*n matrices with n*m matrices");
        }

        Matrix newmatrix = Matrix(rows, m.columns);

        for (int r = 0; r < newmatrix.rows; r++) {
            for (int c = 0; c < newmatrix.columns; c++) {
                for (int k = 0; k < columns; k++) {
                    newmatrix.values[r][c] += values[r][k] * m.values[k][c];
                }
            }
        }
        return newmatrix;
    }

    Matrix Matrix::operator*(double k) const {
        vector<vector<double>> newmatrix = vector<vector<double>>(rows, vector<double>(columns, 0.0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix[i][j] = values[i][j] * k;
            }
        }
        return Matrix(newmatrix);
    }

    Matrix operator*(double k, const Matrix &m) {
        return m * k;
    }

    Matrix Matrix::operator/(double k) const {
        if (k == 0) {
            throw std::invalid_argument("cannot divide a matrix by 0");
        }
        vector<vector<double>> newmatrix = vector<vector<double>>(rows, vector<double>(columns, 0.0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                newmatrix[i][j] = values[i][j] / k;
            }
        }
        return Matrix(newmatrix);
    }


    //Misc
    bool Matrix::operator==(const Matrix& m) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (values[i][j] != m.values[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }


    std::ostream& operator<<(std::ostream& os, const Matrix& m) {
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.columns; j++) {
                os << m.values[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

}
