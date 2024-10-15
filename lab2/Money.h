#ifndef MONEY_H
#define MONEY_H

#include <iostream>
#include "Fraction.h"

class Money {
private:
    Fraction amount;  // представляем сумму с помощью фракшион х

public:
    // Конструкторы
    Money(long long rubles = 0, unsigned short kopecks = 0);
    Money(const Fraction& frac);

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;

    Money operator*(double factor) const;
    Money operator/(double divisor) const;

    double operator/(const Money& other) const;

    bool operator==(const Money& other) const;
    bool operator!=(const Money& other) const;
    bool operator<(const Money& other) const;
    bool operator<=(const Money& other) const;
    bool operator>(const Money& other) const;
    bool operator>=(const Money& other) const;

    // вывод
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    //friend std::istream& operator>>(std::istream& is, Money& money);

    long long getRubles() const;
    unsigned short getKopecks() const;
};

#endif // MONEY_H