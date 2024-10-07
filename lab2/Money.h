#include <iostream>
#include <vector>
#include <string>
#include "Fraction.h"

class Money {
private:
    std::vector<int> amount;  // Массив цифр, представляющий сумму

public:
    // Конструктор
    Money(const std::string& str_amount) {
        if (str_amount.length() > 100) {
            throw std::invalid_argument("Слишком длинная сумма, максимум 100 цифр.");
        }
        // Заполняем вектор цифрами, начиная с младших
        for (auto it = str_amount.rbegin(); it != str_amount.rend(); ++it) {
            amount.push_back(*it - '0');
        }
    }

    // Преобразование в объект Fraction
    Fraction toFraction() const {
        long long whole_part = 0;
        unsigned short fractional_part = 0;

        // Получаем дробную часть
        if (amount.size() >= 2) {
            fractional_part = amount[1] * 10 + amount[0];
        } else if (amount.size() == 1) {
            fractional_part = amount[0];
        }

        // Получаем целую часть
        if (amount.size() > 2) {
            for (size_t i = amount.size() - 1; i >= 2; --i) {
                whole_part = whole_part * 10 + amount[i];
            }
        }

        return Fraction(whole_part, fractional_part);
    }

    // Операция сложения
    Money operator+(const Money& other) const {
        Fraction frac1 = this->toFraction();
        Fraction frac2 = other.toFraction();
        Fraction result = frac1 + frac2;

        return Money(std::to_string(result.getWhole()) + (result.getFractional() < 10 ? "0" : "") + std::to_string(result.getFractional()));
    }

    // Операция вычитания
    Money operator-(const Money& other) const {
        Fraction frac1 = this->toFraction();
        Fraction frac2 = other.toFraction();
        Fraction result = frac1 - frac2;

        return Money(std::to_string(result.getWhole()) + (result.getFractional() < 10 ? "0" : "") + std::to_string(result.getFractional()));
    }

    // Вывод суммы на экран
    friend std::ostream& operator<<(std::ostream& os, const Money& money) {
        for (auto it = money.amount.rbegin(); it != money.amount.rend(); ++it) {
            os << *it;
        }
        return os;
    }
};