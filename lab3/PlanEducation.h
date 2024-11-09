#ifndef PLANEDUCATION_H
#define PLANEDUCATION_H

#include <vector>
#include "Discipline.h"

class PlanEducation {
private:
    std::string code; // код специальности
    std::string specialtyName;
    std::string approvalDate; // дата утверждения
    int standardHours; // общее количество часов по стандарту
    std::vector<Discipline> disciplines;

public:
    PlanEducation(const std::string& code, const std::string& specialtyName, const std::string& approvalDate, int standardHours);

    void addDiscipline(const Discipline& discipline);
    void removeDiscipline(int id);

    std::vector<Discipline> findBySemester(int semester) const;
    std::vector<Discipline> findByType(const std::string& type) const;
    std::vector<Discipline> findByControlType(const std::string& controlType) const;

    int calculateTotalHours() const;
    std::pair<int, int> examsAndTestsBySemester(int semester) const;

    PlanEducation operator+(const PlanEducation& other) const;
    PlanEducation operator-(const PlanEducation& other) const;
    PlanEducation operator*(const PlanEducation& other) const;

    void displayDisciplines() const;
};

#endif