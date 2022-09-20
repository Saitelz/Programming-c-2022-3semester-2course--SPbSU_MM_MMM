#include <iostream>

using namespace std;

class Сoordinate
{
    int x = 1;
    int y = 2;
    int z = 3;

    void printX();
    void printY();
    void printZ();
};

void Сoordinate::printX()
{
    cout << x << endl;
}

void Сoordinate::printY()
{
    cout << y << endl;
}

void Сoordinate::printZ()
{
    cout << z << endl;
}

int main()
{
    Сoordinate A;

    cout << &A << endl;

    int* pA = (int*)(&A);

    cout << "Before x=" << *pA << " after x=";
    *pA = 23;
    cout << *pA << endl;

    pA += 1;
    cout << "Before y=" << *pA << " after y=";
    *pA = 23 * (*pA);
    cout << *pA << endl;

    pA += 1;
    cout << "Before z=" << *pA << " after z=";
    *pA = 23 * (*pA);
    cout << *pA << endl;


    /* void (*pF)() = (void (*)())((long int)&main);

    pF(); */

    return EXIT_SUCCESS;
}
