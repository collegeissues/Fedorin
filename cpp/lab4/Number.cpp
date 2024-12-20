#include "Number.h"
#include <stdexcept>
#include <iostream>

Number::Number(double val) {
    if (std::isnan(val) || std::isinf(val)) {
        std::cerr << "Ошибка: значение должно быть числом." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    value = val;
}

double Number::getValue() const {
    return value;
}

void Number::setValue(double val) {
    if (std::isnan(val) || std::isinf(val)) {
        std::cerr << "Ошибка: значение должно быть числом." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    value = val;
}

double Number::multiply(double other) const {
    if (std::isnan(other) || std::isinf(other)) {
        std::cerr << "Ошибка: множитель должен быть числом." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return value * other;
}

double Number::subtract(double other) const {
    if (std::isnan(other) || std::isinf(other)) {
        std::cerr << "Ошибка: вычитаемое должно быть числом." << std::endl;
        std::exit(EXIT_FAILURE);
    }
    return value - other;
}