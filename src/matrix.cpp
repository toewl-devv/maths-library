#include "maths/matrix.hpp"
#include <stdexcept>
#include <vector>

using namespace std;

namespace maths {
    Matrix::Matrix(int m, int n)
        : rows(m), columns(n),
        values(m, vector<double>(n, 0.0))
        {}

    Matrix::Matrix(vector<vector<double>> data)
        : values(data),
        rows(data.size()),
        columns(data[0].size()) //TODO add error handling incase its empty!
        {}

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
            det += ((i % 2 == 0) * 2 - 1) * nextmatr.det();
        }
        return det;
    }
}
