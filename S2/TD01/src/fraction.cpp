#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// Exo 01
Fraction Fraction::operator+(Fraction const& f) const {
    return simplify({
        numerator * f.denominator + f.numerator * denominator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator-(Fraction const& f) const {
    return simplify({
        numerator * f.denominator - f.numerator * denominator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator*(Fraction const& f) const {
    return simplify({
        numerator * f.numerator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator/(Fraction const& f) const {
    return simplify({
        numerator * f.denominator,
        denominator * f.numerator
        }
    );
}

// Exo 02
std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}

// Exo 03
bool Fraction::operator==(Fraction const& f) const {
    Fraction this_simplify{ simplify(*this) };
    Fraction f_simplify{ simplify(f) };

    return (this_simplify.numerator == f_simplify.numerator) && (this_simplify.denominator == f_simplify.denominator);
}

bool Fraction::operator!=(Fraction const& f) const {
    return !(*this == f);
}

// Exo 04
bool Fraction::operator<(Fraction const& f) const {
    return (numerator / static_cast<float>(denominator)) < (f.numerator / static_cast<float>(f.denominator));
}

bool Fraction::operator<=(Fraction const& f) const {
    return (*this < f) || (*this == f);
}

bool Fraction::operator>(Fraction const& f) const {
    return !(*this <= f);
}

bool Fraction::operator>=(Fraction const& f) const {
    return !(*this < f);
}

// Exo 05
Fraction& Fraction::operator+=(Fraction const& f) {
    *this = *this + f;
    return *this;
}

Fraction& Fraction::operator-=(Fraction const& f) {
    *this = *this - f;
    return *this;
}

Fraction& Fraction::operator*=(Fraction const& f) {
    *this = *this * f;
    return *this;
}

Fraction& Fraction::operator/=(Fraction const& f) {
    *this = *this / f;
    return *this;
}