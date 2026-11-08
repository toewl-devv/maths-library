#include <iostream>
#include "maths/vector3.hpp"
#include "maths/vector2.hpp"
#include "maths/matrix.hpp"

using namespace std;
int main() {
    maths::Vector2 a(3.0, 4.0);
    maths::Vector2 b(2.0, 5.0);

    maths::Vector3 c(5.0, 4.0, 3.0);
    maths::Vector3 d(-1.0, -10.0, 2.0);

    /*
    cout << a + b << endl;
    cout << a - b << endl;
    cout << (a == b) << endl;
    cout << a * b << endl;

    cout << c + d << endl;
    cout << c - d << endl;
    cout << (c == (c-d) + d) << endl;
    cout << c * d << endl;
    */
    /*
    double mag = a.magnitude();
    cout << a << endl;
    a.normalise();
    cout << a << endl;

    cout << a*b << endl;
    cout << "By scalar k=2mag: " << a * 2*mag << endl;

    cout << b << " is b, 2-division: " << b / 2 << endl;
    */

    maths::Matrix m({{1, 2}, {3, 4}});
    
    maths::Matrix m2({
                {1, -2, 3, 4},
                {-4, 5, -6, 6},
                {7, -8, 9, 9},
                {2, 6, 7, 3}
            });

    maths::Matrix m3({
            {1, 2, 3, 4},
            {1, 4, 2, 5},
            {0, 0, 5, -2.5},
        });

    maths::Matrix m4({
            {-1, -2, -3, -4},
            {1, 4, 2, 5},
            {0, 0, 5, -2.5}
        });

    cout << m3 << endl;

    cout << "Transposed:" << endl;

    cout << m3.transpose() << endl;
    
    m3.swap(1, 2);
    cout << m3 << endl;
    m3.scale(3, 1.5);
    cout << m3 << endl;
    m3.addmultiple(1, 2.0, 2);
    cout << m3 << endl;
}
