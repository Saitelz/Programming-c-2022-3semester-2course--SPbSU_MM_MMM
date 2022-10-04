#include "Quaternions.h"
#include <cmath>

Quaternion::Quaternion(double re, double im1, double im2, double im3) :re(re), im1(im1), im2(im2), im3(im3) {}
Quaternion::Quaternion(const Quaternion& Quaternion) : re(Quaternion.re), im1(Quaternion.im1), im2(Quaternion.im2), im3(Quaternion.im3) {}
Quaternion::~Quaternion()
{
    re = 0;
    im1 = 0;
    im2 = 0;
    im3 = 0;
}

double Quaternion::getRe()
{
    return this->re;
}

void Quaternion::setRe(double re)
{
    this->re = re;
}

double Quaternion::getIm1()
{
    return this->im1;
}

void Quaternion::setIm1(double im1)
{
    this->im1 = im1;
}

double Quaternion::getIm2()
{
    return this->im2;
}

void Quaternion::setIm2(double im2)
{
    this->im2 = im2;
}

double Quaternion::getIm3()
{
    return this->im3;
}

void Quaternion::setIm3(double im3)
{
    this->im1 = im3;
}

void Quaternion::set(double re, double im1, double im2, double im3)
{
    this->re = re;
    this->im1 = im1;
    this->im2 = im2;
    this->im3 = im3;
}

void Quaternion::operator=(const Quaternion& complex)
{
    this->re = complex.re;
    this->im1 = complex.im1;
    this->im2 = complex.im2;
    this->im3 = complex.im3;
}

double Quaternion::abs()
{
    return std::sqrt((this->re) * (this->re) + (this->im1) * (this->im1) + (this->im2) * (this->im2) + (this->im3) * (this->im3));
}

Quaternion operator*(Quaternion Quaternion1, Quaternion Quaternion2)
{
    return Quaternion(Quaternion1.re * Quaternion2.re - Quaternion1.im1 * Quaternion2.im1 - Quaternion1.im2 * Quaternion2.im2 - Quaternion1.im3 * Quaternion2.im3, Quaternion1.re * Quaternion2.im1 + Quaternion2.re * Quaternion1.im1 + Quaternion1.im2 * Quaternion2.im3 - Quaternion2.im2 * Quaternion1.im3, Quaternion1.re * Quaternion2.im2 + Quaternion2.re * Quaternion1.im2 + Quaternion1.im3 * Quaternion2.im1 - Quaternion2.im3 * Quaternion1.im1, Quaternion1.re * Quaternion2.im3 + Quaternion2.re * Quaternion1.im3 + Quaternion1.im1 * Quaternion2.im2 - Quaternion2.im1 * Quaternion1.im2);
}

Quaternion operator*(double d, Quaternion quaternion)
{
    return Quaternion(quaternion.re * d, quaternion.im1 * d, quaternion.im2 * d, quaternion.im3 * d);
}

Quaternion operator*(Quaternion quaternion, double d)
{
    return Quaternion(quaternion.re * d, quaternion.im1 * d, quaternion.im2 * d, quaternion.im3 * d);
}

Quaternion operator*=(Quaternion Quaternion1, Quaternion Quaternion2)
{
    Quaternion1 = Quaternion1 * Quaternion2;

    return Quaternion1;
}

Quaternion operator*=(double d, Quaternion quaternion)
{
    quaternion = d * quaternion;

    return quaternion;
}

Quaternion operator*=(Quaternion quaternion, double d)
{
    quaternion = quaternion * d;

    return quaternion;
}

Quaternion operator+(Quaternion Quaternion1, Quaternion Quaternion2)
{
    return Quaternion(Quaternion1.re + Quaternion2.re, Quaternion1.im1 + Quaternion2.im1, Quaternion1.im2 + Quaternion2.im2, Quaternion1.im3 + Quaternion2.im3);
}

Quaternion operator+=(Quaternion Quaternion1, Quaternion Quaternion2)
{
    Quaternion1 = Quaternion1 + Quaternion2;

    return Quaternion1;
}

Quaternion operator/(Quaternion Quaternion1, Quaternion Quaternion2)
{
    double var = Quaternion2.re * Quaternion2.re + Quaternion2.im1 * Quaternion2.im1 + Quaternion2.im2 * Quaternion2.im2 + Quaternion2.im3 * Quaternion2.im3;
    return Quaternion((Quaternion1.re * Quaternion2.re - Quaternion1.im1 * Quaternion2.im1 - Quaternion1.im2 * Quaternion2.im2 - Quaternion1.im3 * Quaternion2.im3)/var, (Quaternion1.re * Quaternion2.im1 + Quaternion2.re * Quaternion1.im1 + Quaternion1.im2 * Quaternion2.im3 - Quaternion2.im2 * Quaternion1.im3)/var, (Quaternion1.re * Quaternion2.im2 + Quaternion2.re * Quaternion1.im2 + Quaternion1.im3 * Quaternion2.im1 - Quaternion2.im3 * Quaternion1.im1)/var, (Quaternion1.re * Quaternion2.im3 + Quaternion2.re * Quaternion1.im3 + Quaternion1.im1 * Quaternion2.im2 - Quaternion2.im1 * Quaternion1.im2)/var);
}

Quaternion operator/=(Quaternion Quaternion1, Quaternion Quaternion2)
{
    Quaternion1 = Quaternion1 / Quaternion2;

    return Quaternion1;
}

Quaternion operator-(Quaternion Quaternion1, Quaternion Quaternion2)
{
    return Quaternion(Quaternion1.re - Quaternion2.re, Quaternion1.im1 - Quaternion2.im1, Quaternion1.im2 - Quaternion2.im2,Quaternion1.im3 - Quaternion2.im3);
}

Quaternion operator-=(Quaternion Quaternion1, Quaternion Quaternion2)
{
    Quaternion1 = Quaternion1 - Quaternion2;

    return Quaternion1;
}

void swap(Quaternion Quaternion1, Quaternion Quaternion2)
{
    Quaternion Quaternion3;

    Quaternion3 = Quaternion2;
    Quaternion2 = Quaternion1;
    Quaternion1 = Quaternion3;
}

std::ostream& operator<<(std::ostream& stream, const Quaternion& Quaternion)
{
    if (Quaternion.im1 < 0)
    {
        if (Quaternion.im1 == -1)
        {
            stream << Quaternion.re << " -i";
        }
        else
        {
            stream << Quaternion.re << " -" << Quaternion.im1 << "i";
        }
    }
    else if (Quaternion.im1 == 0)
    {
        stream << Quaternion.re;
    }
    else
    {
        if (Quaternion.im1 == 1)
        {
            stream << Quaternion.re << " +i";
        }
        else
        {
            stream << Quaternion.re << " +" << Quaternion.im1 << "i";
        }
    }

    if (Quaternion.im2 < 0)
    {
        if (Quaternion.im2 == -1)
        {
            stream << Quaternion.re << " -j";
        }
        else
        {
            stream << Quaternion.re << " -" << Quaternion.im2 << "j";
        }
    }
    else if (Quaternion.im2 == 0)
    {
        stream << Quaternion.re;
    }
    else
    {
        if (Quaternion.im2 == 1)
        {
            stream << Quaternion.re << " +j";
        }
        else
        {
            stream << Quaternion.re << " +" << Quaternion.im2 << "j";
        }
    }

    if (Quaternion.im3 < 0)
    {
        if (Quaternion.im3 == -1)
        {
            stream << Quaternion.re << " -k";
        }
        else
        {
            stream << Quaternion.re << " -" << Quaternion.im3 << "k";
        }
    }
    else if (Quaternion.im3 == 0)
    {
        stream << Quaternion.re;
    }
    else
    {
        if (Quaternion.im3 == 1)
        {
            stream << Quaternion.re << " +k";
        }
        else
        {
            stream << Quaternion.re << " +" << Quaternion.im3 << "k";
        }
    }

    return stream;
}