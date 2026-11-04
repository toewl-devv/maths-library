#include <cmath>
#include "maths/vector2.hpp"

namespace maths {

    Vector2::Vector2(double x, double y)
        : x(x), y(y) {}

    double Vector2::magnitude() const {
        return std::sqrt(x * x + y * y);
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

    bool Vector2::operator==(const Vector2& v) {
        return (x == v.x && y == v.y);
    }

    std::ostream& operator<<(std::ostream& os, const Vector2& v) {
        return os << "(" << v.x << ", " << v.y << ")";
    }

}
