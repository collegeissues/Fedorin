#include <ncurses.h>
#include <iostream>
#include "Number.h"
#include "Real.h"
//#include "MenuDrawer.h"

//MenuDrawer menu;

int main() {

//    menu.StartDrawing();
//    menu.StartMenu();
	try {
		Number num(10.0);
		std::cout << "Number: " << num.getValue() << std::endl;
		std::cout << "Multiply by 2: " << num.multiply(2.0) << std::endl;
		std::cout << "Subtract 3: " << num.subtract(3.0) << std::endl;

		Real realNum(16.0);
		std::cout << "\nReal Number: " << realNum.getValue() << std::endl;
		std::cout << "Square root: " << realNum.root(2.0) << std::endl;
		std::cout << "Cube root: " << realNum.root(3.0) << std::endl;
		std::cout << "Power 3: " << realNum.power(3.0) << std::endl;

		Real invalidNum(-16.0);

	} catch (const std::exception &e) {
		std::cerr << "Исключение: " << e.what() << std::endl;
	}
}