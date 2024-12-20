#ifndef DISCIPLINE_H
#define DISCIPLINE_H

#include <string>

struct Discipline {
    int id;
    std::string type;
    std::string name;
    int semester;
    std::string controlType; // вид итогового контроля (зачет или экзамен)
    int totalHours;
    int lectureHours;
    int practiceHours;
    bool hasCourseWork; // наличие курсовой работы

    int selfStudyHours() const {
        return totalHours - (lectureHours + practiceHours); // количество часов для самостоятельной работы
    }
};

#endif