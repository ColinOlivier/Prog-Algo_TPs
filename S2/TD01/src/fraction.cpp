#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

Fraction Fraction::operator+(Fraction const& f) {
    return simplify({
        numerator * f.denominator + f.numerator * denominator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator-(Fraction const& f) {
    return simplify({
        numerator * f.denominator - f.numerator * denominator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator*(Fraction const& f) {
    return simplify({
        numerator * f.numerator,
        denominator * f.denominator
        }
    );
}

Fraction Fraction::operator/(Fraction const& f) {
    return simplify({
        numerator * f.denominator,
        denominator * f.numerator
        }
    );
}

std::ostream& operator<<(std::ostream& os, Fraction const& f) {
    return os << f.numerator << "/" << f.denominator;
}
