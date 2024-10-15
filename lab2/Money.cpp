#include "Money.h"
#include <stdexcept>
#include <iomanip>

// Конструктор из рублей и копеек
Money::Money(long long rubles, unsigned short kopecks)
    : amount(rubles, kopecks) {
}

// Конструктор из Fraction
Money::Money(const Fraction& frac)
    : amount(frac) {
}

Money Money::operator+(const Money& other) const {
    Fraction result = amount + other.amount;
    return Money(result);
}

Money Money::operator-(const Money& other) const {
    Fraction result = amount - other.amount;
    return Money(result);
}

Money Money::operator*(double factor) const {
    long long total_kopecks = amount.getWhole() * 100 + amount.getFractional();
    long long result_total = static_cast<long long>(total_kopecks * factor);

    long long new_rubles = result_total / 100;
    unsigned short new_kopecks = result_total % 100;

    return Money(new_rubles, new_kopecks);
}

Money Money::operator/(double divisor) const {
    if (divisor == 0.0) {
        throw std::invalid_argument("Division by zero");
    }

    long long total_kopecks = amount.getWhole() * 100 + amount.getFractional();
    long long result_total = static_cast<long long>(total_kopecks / divisor);

    long long new_rubles = result_total / 100;
    unsigned short new_kopecks = result_total % 100;

    return Money(new_rubles, new_kopecks);
}

double Money::operator/(const Money& other) const {
    long long total_kopecks1 = amount.getWhole() * 100 + amount.getFractional();
    long long total_kopecks2 = other.amount.getWhole() * 100 + other.amount.getFractional();

    if (total_kopecks2 == 0) {
        throw std::invalid_argument("Division by zero");
    }

    return static_cast<double>(total_kopecks1) / static_cast<double>(total_kopecks2);
}

bool Money::operator==(const Money& other) const {
    return amount == other.amount;
}

bool Money::operator!=(const Money& other) const {
    return amount != other.amount;
}

bool Money::operator<(const Money& other) const {
    return amount < other.amount;
}

bool Money::operator<=(const Money& other) const {
    return amount <= other.amount;
}

bool Money::operator>(const Money& other) const {
    return amount > other.amount;
}

bool Money::operator>=(const Money& other) const {
    return amount >= other.amount;
}

// вывод
std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.amount;
    return os;
}

// Оператор ввода
// std::istream& operator>>(std::istream& is, Money& money) {
//     char comma;
//     long long rubles_input;
//     unsigned short kopecks_input;
//
//     is >> rubles_input >> comma >> kopecks_input;
//
//     if (comma != ',' || kopecks_input >= 100) {
//         is.setstate(std::ios::failbit);
//         return is;
//     }
//
//     money.amount = Fraction(rubles_input, kopecks_input);
//     return is;
// }

long long Money::getRubles() const {
    return amount.getWhole();
}

unsigned short Money::getKopecks() const {
    return amount.getFractional();
}