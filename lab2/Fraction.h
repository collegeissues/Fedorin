#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    long long whole;              // Целая часть (знаковое длинное целое)
    unsigned short fractional;    // Дробная часть (беззнаковое короткое целое)

public:
    // Конструктор с параметрами по умолчанию
    Fraction(long long whole_part = 0, unsigned short fractional_part = 0);

    // Арифметические операции
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;

    // Операции сравнения
    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    // Дружественная функция для вывода дроби
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif // FRACTION_H