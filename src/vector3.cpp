#include <cmath>
#include "maths/vector3.hpp"

namespace maths {

    Vector3::Vector3(double x, double y, double z)
        : x(x), y(y), z(z) {}

    double Vector3::magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3 Vector3::operator+(const Vector3 &v) {
        return Vector3(x + v.x, y + v.y, z + v.z);
    }

    Vector3 Vector3::operator-(const Vector3 &v) {
        return Vector3(x - v.x, y - v.y, z - v.z);
    }

    double Vector3::operator*(const Vector3 &v) {
        return x * v.x + y * v.y + z * v.z;
    }

    bool Vector3::operator==(const Vector3& v) {
        return (x == v.x && y == v.y && z == v.z);
    }

    std::ostream& operator<<(std::ostream& os, const Vector3& v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }

}
