#include <iostream>
#include "Fraction.h"

int main() {
    Fraction frac1(3, 500);  // Представляет число 3.500
    Fraction frac2(1, 750);  // Представляет число 1.750

    Fraction sum = frac1 + frac2;
    Fraction diff = frac1 - frac2;
    Fraction prod = frac1 * frac2;

    std::cout << "Frac1: " << frac1 << std::endl;
    std::cout << "Frac2: " << frac2 << std::endl;

    std::cout << "Sum: " << sum << std::endl;          // Ожидается 5.250
    std::cout << "Difference: " << diff << std::endl;  // Ожидается 1.750
    std::cout << "Product: " << prod << std::endl;     // Ожидается 5.250

    // Проверка операций сравнения
    if (frac1 > frac2) {
        std::cout << frac1 << " > " << frac2 << std::endl;
    } else if (frac1 < frac2) {
        std::cout << frac1 << " < " << frac2 << std::endl;
    } else {
        std::cout << frac1 << " == " << frac2 << std::endl;
    }

    return 0;
}