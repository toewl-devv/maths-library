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
        return 0;
    }
}
