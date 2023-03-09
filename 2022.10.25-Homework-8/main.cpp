#include <iostream>
#include <fstream>
#include <string>
#include "Vector.h"

using namespace std;
 
int main(int argc, char *argv[])
{
    int n = 0;

    cin >> n;

    Vector<double> f;
    f.resize(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> f[i];
    }       
    
    cout << f << endl; 

    ofstream out; // поток для записи
    out.open("Vector.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < n; ++i)
        {
            out << f[i] << endl;
        }  
    } 
    out.close();

    string line;
 
    ifstream in("Vector.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int itr = 0;
        while (getline(in, line))
        {
            cout << line << endl;
            itr++;
        }

        Vector<double> newf;
        newf.resize(itr);

        int tmp = 0;
       while (getline(in, line))
        {
            newf[tmp] = line; //как преобразовать string в нужный нам тип?
            tmp++;
        } 

        cout << newf << endl; 
    } 
    in.close();     // закрываем файл

    return EXIT_SUCCESS;
}