#include "Fraction.h"
#include <stdexcept>
#include <iomanip>

// Конструктор класса Fraction
Fraction::Fraction(long long whole_part, unsigned short fractional_part)
    : whole(whole_part), fractional(fractional_part) {
    normalize();
}

// Нормализация дробной части
void Fraction::normalize() {
    if (fractional >= 100) {
        whole += fractional / 100;
        fractional = fractional % 100;
    } else if (fractional < 0) {
        long long k = (-fractional) / 100 + 1;
        whole -= k;
        fractional += k * 100;
    }
}

long long Fraction::getWhole() const {
    return whole;
}

unsigned short Fraction::getFractional() const {
    return fractional;
}

Fraction Fraction::operator+(const Fraction& other) const {
    long long new_whole = whole + other.whole;
    unsigned short new_fractional = fractional + other.fractional;

    return Fraction(new_whole, new_fractional);
}

Fraction Fraction::operator-(const Fraction& other) const {
    long long new_whole = whole - other.whole;
    int new_fractional = fractional - other.fractional;

    return Fraction(new_whole, static_cast<unsigned short>(new_fractional));
}

Fraction Fraction::operator*(const Fraction& other) const {
    long long total1 = whole * 100 + fractional;
    long long total2 = other.whole * 100 + other.fractional;

    long long result_total = (total1 * total2) / 100;
    long long new_whole = result_total / 100;
    unsigned short new_fractional = result_total % 100;

    return Fraction(new_whole, new_fractional);
}




bool Fraction::operator==(const Fraction& other) const {
    return whole == other.whole && fractional == other.fractional;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (whole == other.whole) {
        return fractional < other.fractional;
    }
    return whole < other.whole;
}

bool Fraction::operator<=(const Fraction& other) const {
    return *this < other || *this == other;
}

bool Fraction::operator>(const Fraction& other) const {
    return !(*this <= other);
}

bool Fraction::operator>=(const Fraction& other) const {
    return !(*this < other);
}

// dsdjl
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.whole << ',';
    os << std::setw(2) << std::setfill('0') << frac.fractional;
    return os;
}