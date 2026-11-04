// makes header file only be included one
#pragma once

#include <ostream>

namespace maths {

    class Vector3 {
        public:
            double x;
            double y;
            double z;

            Vector3(double x, double y, double z);

            double magnitude() const;
            
            Vector3 operator+(const Vector3 &v);
            Vector3 operator-(const Vector3 &v);

            double operator*(const Vector3 &v);
            bool operator==(const Vector3 &v);

            friend std::ostream& operator<<(std::ostream& os, const Vector3& v);
    };
}
