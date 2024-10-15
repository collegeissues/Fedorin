#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    long long whole;
    unsigned short fractional;
    void normalize();

public:

    Fraction(long long whole_part = 0, unsigned short fractional_part = 0);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;

    long long getWhole() const;
    unsigned short getFractional() const;

    // dsdjl
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif