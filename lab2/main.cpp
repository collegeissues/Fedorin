#include <iostream>
#include "Money.h"

int main() {
    Money m1(100, 50);
    Money m2(200, 75);

    Money sum = m1 + m2;
    std::cout << m1 << " + " << m2 << " = " << sum << std::endl;

    Money diff = m2 - m1;
    std::cout << m2 << " - " << m1 << " = " << diff << std::endl;

    double factor = 1.5;
    Money product = m1 * factor;
    std::cout << m1 << " * " << factor << " = " << product << std::endl;

    double divisor = 2.0;
    Money quotient = m2 / divisor;
    std::cout << m2 << " / " << divisor << " = " << quotient << std::endl;

    double ratio = m2 / m1;
    std::cout << m2 << " / " << m1 << " = " << ratio << std::endl;

    if (m1 < m2) {
        std::cout << m1 << " меньше " << m2 << std::endl;
    } else {
        std::cout << m1 << " не меньше " << m2 << std::endl;
    }

    // Ввод
    // Money m3;
    // std::cout << "Введите сумму в формате 'рубли,копейки': ";
    // if (std::cin >> m3) {
    //     std::cout << "Вы ввели: " << m3 << std::endl;
    // } else {
    //     std::cerr << "Неверный формат ввода." << std::endl;
    // }
    return 0;
}