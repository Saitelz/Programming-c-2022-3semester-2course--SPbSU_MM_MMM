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

//    void (*pF)() = (void (*)())((long int)&main + ???);
//
//    pF();
//
//    Компилятор не позволяет, но нужно найти адрес функции printX и численное смещение адреса от него до main, вместо "???"
//    подставить число на которое различаются адреса, так мы попадём на область памяти printX и сможем вызвать её с помощью указателя pF
//
//    Остальные закрытые функции можно так же найти по смещению

    return EXIT_SUCCESS;
}
