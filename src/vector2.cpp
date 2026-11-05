#include <cmath>
#include <stdexcept>
#include "maths/vector2.hpp"

namespace maths {

    Vector2::Vector2(double x, double y)
        : x(x), y(y) {}

    double Vector2::magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    void Vector2::normalise() {
        double mag = magnitude();
        x /= mag;
        y /= mag;
    }

    Vector2 Vector2::operator+(const Vector2 &v) {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 Vector2::operator-(const Vector2 &v) {
        return Vector2(x - v.x, y - v.y);
    }

    double Vector2::operator*(const Vector2 &v) {
        return x * v.x + y * v.y;
    }

    Vector2 Vector2::operator*(double k) {
        return Vector2(k * x, k* y);
    }

    /*
    Vector2 int::operator*(Vector2 &v) { // figure this out
    }
    */

    Vector2 Vector2::operator/(double k) {
        if (k == 0) {
            throw std::invalid_argument("cannot divide a vector by 0");
        }
        return Vector2(x / k, y / k);
    }


    bool Vector2::operator==(const Vector2& v) {
        return (x == v.x && y == v.y);
    }

    std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }

}
