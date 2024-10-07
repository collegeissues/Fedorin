#include <iostream>
#include <stdexcept>

class Fraction {
private:
    long long whole;  // Целая часть
    unsigned short fractional;  // Дробная часть (копейки)

public:
    Fraction(long long w = 0, unsigned short f = 0) {
        if (f >= 100) {
            throw std::invalid_argument("Дробная часть не может быть больше 99");
        }
        whole = w;
        fractional = f;
    }

    // Геттер для целой
    long long getWhole() const {
        return whole;
    }

    // Геттер для дробной
    unsigned short getFractional() const {
        return fractional;
    }

    // Операция сложения
    Fraction operator+(const Fraction& other) const {
        long long new_whole = whole + other.whole;
        unsigned short new_fractional = fractional + other.fractional;
        if (new_fractional >= 100) {
            new_whole += new_fractional / 100;
            new_fractional %= 100;
        }
        return Fraction(new_whole, new_fractional);
    }

    // Операция вычитания
    Fraction operator-(const Fraction& other) const {
        long long new_whole = whole - other.whole;
        short new_fractional = fractional - other.fractional;
        if (new_fractional < 0) {
            new_whole -= 1;
            new_fractional += 100;
        }
        return Fraction(new_whole, new_fractional);
    }

    // Операция умножения на целое число
    Fraction operator*(int multiplier) const {
        long long total_fractional = (whole * 100 + fractional) * multiplier;
        long long new_whole = total_fractional / 100;
        unsigned short new_fractional = total_fractional % 100;
        return Fraction(new_whole, new_fractional);
    }

    // Операция сравнения (равенство)
    bool operator==(const Fraction& other) const {
        return whole == other.whole && fractional == other.fractional;
    }

    bool operator<(const Fraction& other) const {
        if (whole == other.whole) {
            return fractional < other.fractional;
        }
        return whole < other.whole;
    }

    // Вывод в строку
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.whole << "." << (frac.fractional < 10 ? "0" : "") << frac.fractional;
        return os;
    }
};