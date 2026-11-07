// makes header file only be included one
#pragma once

#include <ostream>

namespace maths {

    class Vector2 {
        public:
            double x;
            double y;

            Vector2(double x, double y);

            double magnitude() const;
            void normalise();
            
            Vector2 operator+(const Vector2 &v) const;
            Vector2 operator-(const Vector2 &v) const;
            double operator*(const Vector2 &v) const;
 
            Vector2 operator*(double k) const;

            Vector2 operator/(double k);

            bool operator==(const Vector2 &v);

            friend std::ostream& operator<<(std::ostream& os, const Vector2& v);
    };

    Vector2 operator*(double k, const Vector2 &v);
}
