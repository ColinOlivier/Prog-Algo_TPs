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
};

std::ostream& operator<<(std::ostream& os, Fraction const& f);