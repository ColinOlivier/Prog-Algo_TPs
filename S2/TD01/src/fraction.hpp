#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    Fraction operator+(Fraction const& f) const;
    Fraction operator-(Fraction const& f) const;
    Fraction operator*(Fraction const& f) const;
    Fraction operator/(Fraction const& f) const;

    bool operator==(Fraction const& f) const;
    bool operator!=(Fraction const& f) const;

    bool operator<(Fraction const& f) const;
    bool operator<=(Fraction const& f) const;
    bool operator>(Fraction const& f) const;
    bool operator>=(Fraction const& f) const;

    Fraction& operator+=(Fraction const& f);
    Fraction& operator-=(Fraction const& f);
    Fraction& operator*=(Fraction const& f);
    Fraction& operator/=(Fraction const& f);

    float to_float() const;
    operator float() const;

    Fraction operator+(int const i) const;
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);

int ceil(Fraction const& f);
int floor(Fraction const& f);
int round(Fraction const& f);