#include <iostream>
#include "Vector.h"

using namespace std;

int main()
{
    Vector<int> test;
    test.resize(10);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.insert(5, 23);
    test[2] = 3;

    cout << test;

    return EXIT_SUCCESS;
}