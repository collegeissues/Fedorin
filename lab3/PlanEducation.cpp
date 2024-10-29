#include "PlanEducation.h"
#include <algorithm>

PlanEducation::PlanEducation(const std::string& code, const std::string& specialtyName, const std::string& approvalDate, int standardHours)
    : code(code), specialtyName(specialtyName), approvalDate(approvalDate), standardHours(standardHours) {}

void PlanEducation::addDiscipline(const Discipline& discipline) {
    disciplines.push_back(discipline);
}

void PlanEducation::removeDiscipline(int id) {
    disciplines.erase(
        std::remove_if(disciplines.begin(), disciplines.end(), [id](const Discipline& d) { return d.id == id; }),
        disciplines.end()
    );
}

std::vector<Discipline> PlanEducation::findBySemester(int semester) const {
    std::vector<Discipline> result;
    for (const auto& discipline : disciplines) {
        if (discipline.semester == semester) {
            result.push_back(discipline);
        }
    }
    return result;
}

std::vector<Discipline> PlanEducation::findByType(const std::string& type) const {
    std::vector<Discipline> result;
    for (const auto& discipline : disciplines) {
        if (discipline.type == type) {
            result.push_back(discipline);
        }
    }
    return result;
}

std::vector<Discipline> PlanEducation::findByControlType(const std::string& controlType) const {
    std::vector<Discipline> result;
    for (const auto& discipline : disciplines) {
        if (discipline.controlType == controlType) {
            result.push_back(discipline);
        }
    }
    return result;
}

int PlanEducation::calculateTotalHours() const {
    int total = 0;
    for (const auto& discipline : disciplines) {
        total += discipline.totalHours;
    }
    return total;
}

std::pair<int, int> PlanEducation::examsAndTestsBySemester(int semester) const {
    int exams = 0;
    int tests = 0;
    for (const auto& discipline : disciplines) {
        if (discipline.semester == semester) {
            if (discipline.controlType == "экзамен") exams++;
            else if (discipline.controlType == "зачет") tests++;
        }
    }
    return { exams, tests };
}

PlanEducation PlanEducation::operator+(const PlanEducation& other) const {
    PlanEducation result = *this;
    for (const auto& discipline : other.disciplines) {
        if (std::find_if(result.disciplines.begin(), result.disciplines.end(),
                         [&](const Discipline& d) { return d.id == discipline.id; }) == result.disciplines.end()) {
            result.addDiscipline(discipline);
        }
    }
    return result;
}

PlanEducation PlanEducation::operator-(const PlanEducation& other) const {
    PlanEducation result = *this;
    for (const auto& discipline : other.disciplines) {
        result.removeDiscipline(discipline.id);
    }
    return result;
}

PlanEducation PlanEducation::operator*(const PlanEducation& other) const {
    PlanEducation result(code, specialtyName, approvalDate, standardHours);
    for (const auto& discipline : disciplines) {
        if (std::find_if(other.disciplines.begin(), other.disciplines.end(),
                         [&](const Discipline& d) { return d.id == discipline.id; }) != other.disciplines.end()) {
            result.addDiscipline(discipline);
        }
    }
    return result;
}