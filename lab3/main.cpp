// main.cpp

#include "PlanEducation.h"
#include <iostream>

int main() {
    PlanEducation plan("1234", "Программирование", "2023-01-01", 3000);
    Discipline d1 = {1, "федеральная", "Математика", 1, "экзамен", 100, 50, 30, false};
    Discipline d2 = {2, "региональная", "Физика", 2, "зачет", 80, 40, 20, true};

    plan.addDiscipline(d1);
    plan.addDiscipline(d2);

    // вызов функций
    auto disciplinesBySemester = plan.findBySemester(1);
    int totalHours = plan.calculateTotalHours();

    std::cout << "Суммарное количество часов: " << totalHours << std::endl;

    // перегрузка
    PlanEducation plan2 = plan + plan;
    std::cout << "Количество дисциплин после объединения: " << plan2.calculateTotalHours() << std::endl;

    return 0;
}