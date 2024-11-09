#include <iostream>
#include <string>
#include "PlanEducation.h"

int main() {
    PlanEducation plan1("1234", "Программирование", "2023-01-01", 3000);
    Discipline d1 = {1, "федеральная", "Математика", 1, "экзамен", 100, 50, 30, false};
    Discipline d2 = {2, "региональная", "Физика", 2, "зачет", 80, 40, 20, true};
    plan1.addDiscipline(d1);
    plan1.addDiscipline(d2);

    PlanEducation plan2("1235", "Физика", "2024-01-01", 2500);
    Discipline d3 = {3, "федеральная", "Химия", 1, "экзамен", 90, 45, 25, false};
    Discipline d4 = {2, "региональная", "Физика", 2, "зачет", 80, 40, 20, true};
    plan2.addDiscipline(d3);
    plan2.addDiscipline(d4);

    std::cout << "\nРезультат объединения:\n";
    PlanEducation unionPlan = plan1 + plan2;
    unionPlan.displayDisciplines();

    std::cout << "\nРезультат вычитания:\n";
    PlanEducation subtractionPlan = plan1 - plan2;
    subtractionPlan.displayDisciplines();

    std::cout << "\nРезультат пересечения:\n";
    PlanEducation intersectionPlan = plan1 * plan2;
    intersectionPlan.displayDisciplines();

    return 0;
}