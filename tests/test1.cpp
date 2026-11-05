#include "maths/vector3.hpp"
#include <iostream>
#include <maths/vector2.hpp>

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
    double mag = a.magnitude();
    cout << a << endl;
    a.normalise();
    cout << a << endl;

    cout << a*b << endl;
    cout << "By scalar k=2mag: " << a * 2*mag << endl;

    cout << b << " is b, 2-division: " << b / 2 << endl;


}
