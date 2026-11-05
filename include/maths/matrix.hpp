#pragma once

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
    };
}
