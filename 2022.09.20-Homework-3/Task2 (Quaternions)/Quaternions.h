#pragma once
#include <iostream>

class Quaternion
{
private:

    double re;
    double im1;
    double im2;
    double im3;

public:

    Quaternion(double re = 0, double im1 = 0, double im2 = 0, double im3 = 0);
    Quaternion(const Quaternion& Quaternion);
    ~Quaternion();

    double getRe();
    void setRe(double re);
    double getIm1();
    void setIm1(double im1);
    double getIm2();
    void setIm2(double im2);
    double getIm3();
    void setIm3(double im3);

    void set(double re, double im1, double im2, double im3);

    void operator=(const Quaternion& Quaternion);

    double abs();

    friend Quaternion operator*(Quaternion Quaternion1, Quaternion Quaternion2);
    friend Quaternion operator*(double d, Quaternion quaternion);
    friend Quaternion operator*(Quaternion quaternion, double d);
    friend Quaternion operator*=(Quaternion Quaternion1, Quaternion Quaternion2);
    friend Quaternion operator*=(double d, Quaternion quaternion);
    friend Quaternion operator*=(Quaternion quaternion, double d);

    friend Quaternion operator+(Quaternion Quaternion1, Quaternion Quaternion2);
    friend Quaternion operator+=(Quaternion Quaternion1, Quaternion Quaternion2);

    friend Quaternion operator/(Quaternion Quaternion1, Quaternion Quaternion2);
    friend Quaternion operator/=(Quaternion Quaternion1, Quaternion Quaternion2);

    friend Quaternion operator-(Quaternion Quaternion1, Quaternion Quaternion2);
    friend Quaternion operator-=(Quaternion Quaternion1, Quaternion Quaternion2);

    friend void swap(Quaternion Quaternion1, Quaternion Quaternion2);

    friend std::ostream& operator<<(std::ostream& stream, const Quaternion& Quaternion);
};