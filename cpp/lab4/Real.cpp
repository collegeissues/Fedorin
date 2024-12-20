#include "Real.h"
#include <stdexcept>
#include <cmath>
#include <iostream>

Real::Real(double val) : Number(val) {
    if (val < 0) {
        std::cerr << "Ошибка: число не может быть отрицательным для класса Real." << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

double Real::root(double degree) const {
    if (degree == 0) {
        std::cerr << "Ошибка: степень корня не может быть равна нулю." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (value < 0 && static_cast<int>(degree) % 2 == 0) {
        std::cerr << "Ошибка: невозможно извлечь корень чётной степени из отрицательного числа." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return std::pow(value, 1.0 / degree);
}

double Real::power(double exponent) const {
    if (std::isnan(exponent) || std::isinf(exponent)) {
        std::cerr << "Ошибка: степень должна быть числом." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return std::pow(value, exponent);
}