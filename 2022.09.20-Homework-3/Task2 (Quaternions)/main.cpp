#include <iostream>
#include "Quaternions.h"

using namespace std;

int main()
{
    Quaternion z1(3, 1, 4, 5);
    Quaternion z2(5, -2, 2, 3);

    cout << z1 * z2 << endl;
    cout << z1 / z2 << endl;
    cout << 3 * z1 + 4 * z2 << endl;
    cout << z1.abs() << endl;
    cout << z1 - z2 << endl;


    return 0;
}
