#include "Money.h"

int main()
{
    // Пример использования классов
    Money money1("12345");  // Представляет 123.45 рублей
    Money money2("67890");  // Представляет 678.90 рублей

    std::cout << "Сложение: " << money1 + money2 << std::endl;
    std::cout << "Вычитание: " << money1 - money2 << std::endl;
}