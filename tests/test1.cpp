#include <iostream>
#include <maths/vector2.hpp>

using namespace std;
int main() {
    maths::Vector2 a(3.0, 4.0);
    maths::Vector2 b(2.0, 5.0);

    cout << a + b << endl;
    cout << a - b << endl;
    cout << (a == b) << endl;
    cout << a * b << endl;

}
