#include <iostream>

using namespace std;

struct Types
{
    bool x1;
    char x2;
    short x3;
    float x4;
    int x5;
    long x6;
    long long x7;
    double x8;
};

int main(int argc, char* argv[])
{
    cout << sizeof(bool) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(short) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(double) << endl;

    cout << "Size of struct: " << sizeof(Types) << endl;

    int arr[8] = {1, 1, 2, 4, 4, 8, 8, 8};

    int sum = 0;
    int var_sum = 0;

    for (int i = 0; i < 8; ++i)
    {
        if (var_sum % arr[i] == 0)
        {
            var_sum += arr[i];
        }
        else
        {
            var_sum += arr[i] - (var_sum % arr[i]) + arr[i];
        }
    }

    sum = max(sum, var_sum);

    cout << "Max: " << sum << endl;

    return EXIT_SUCCESS;
}