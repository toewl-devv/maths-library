#pragma once

#include <ostream>
#include <vector>

namespace maths {
    
    class Matrix {
        public:
            int rows;
            int columns;
            std::vector<std::vector<double>> values;

            Matrix(int m, int n);
            Matrix(std::vector<std::vector<double>>);

            double det() const;

            Matrix transpose() const;

            Matrix operator+(const Matrix &m) const;
            Matrix operator-(const Matrix &m) const;
            Matrix operator*(const Matrix &m) const;

            Matrix operator/(double k) const;
            Matrix operator*(double k) const;

            bool operator==(const Matrix &m);

            friend std::ostream& operator<<(std::ostream& os, const Matrix& m);

            void swap(int r1, int r2);
            void scale(int row, double lambda);
            void addmultiple(int r1, double lambda, int r2);
    };

    Matrix operator*(double k, const Matrix &m);
}
