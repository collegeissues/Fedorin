#include "Fraction.h"
#include <stdexcept>

// Конструктор класса Fraction
Fraction::Fraction(long long whole_part, unsigned short fractional_part)
    : whole(whole_part), fractional(fractional_part) {
    if (fractional_part >= 1000) {
        throw std::invalid_argument("Fractional part must be less than 1000");
    }
}

// Операция сложения
Fraction Fraction::operator+(const Fraction& other) const {
    long long new_whole = this->whole + other.whole;
    unsigned short new_fractional = this->fractional + other.fractional;

    // Перенос единицы в целую часть, если дробная часть превышает 999
    if (new_fractional >= 1000) {
        new_whole += 1;
        new_fractional -= 1000;
    }

    return Fraction(new_whole, new_fractional);
}

// Операция вычитания
Fraction Fraction::operator-(const Fraction& other) const {
    long long new_whole = this->whole - other.whole;
    unsigned short new_fractional;

    if (this->fractional >= other.fractional) {
        new_fractional = this->fractional - other.fractional;
    } else {
        new_fractional = (this->fractional + 1000) - other.fractional;
        new_whole -= 1;
    }

    return Fraction(new_whole, new_fractional);
}

// Операция умножения
Fraction Fraction::operator*(const Fraction& other) const {
    long long total1 = this->whole * 1000 + this->fractional;
    long long total2 = other.whole * 1000 + other.fractional;

    long long result_total = (total1 * total2) / 1000;
    long long new_whole = result_total / 1000;
    unsigned short new_fractional = result_total % 1000;

    return Fraction(new_whole, new_fractional);
}

// Операторы сравнения
bool Fraction::operator==(const Fraction& other) const {
    return this->whole == other.whole && this->fractional == other.fractional;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const {
    if (this->whole == other.whole) {
        return this->fractional < other.fractional;
    }
    return this->whole < other.whole;
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

// Оператор вывода в поток
std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.whole << ".";

    // Обеспечиваем вывод ведущих нулей для дробной части
    if (frac.fractional < 10)
        os << "00" << frac.fractional;
    else if (frac.fractional < 100)
        os << "0" << frac.fractional;
    else
        os << frac.fractional;

    return os;
}