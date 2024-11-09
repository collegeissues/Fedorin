#include "PlanEducation.h"
#include <algorithm>
#include <iostream>

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
    if (result.empty()) {
        std::cout << "Дисциплины для семестра " << semester << " не найдены.\n";
    } else {
        std::cout << "Дисциплины, найденные по семестру " << semester << ":\n";
        for (const auto& d : result) {
            std::cout << " - " << d.name << " (ID: " << d.id << ")\n";
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
    if (result.empty()) {
        std::cout << "Дисциплины типа \"" << type << "\" не найдены.\n";
    } else {
        std::cout << "Дисциплины, найденные по типу \"" << type << "\":\n";
        for (const auto& d : result) {
            std::cout << " - " << d.name << " (ID: " << d.id << ")\n";
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
    if (result.empty()) {
        std::cout << "Дисциплины с видом итогового контроля \"" << controlType << "\" не найдены.\n";
    } else {
        std::cout << "Дисциплины, найденные по виду итогового контроля \"" << controlType << "\":\n";
        for (const auto& d : result) {
            std::cout << " - " << d.name << " (ID: " << d.id << ")\n";
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
    std::cout << "дублирующиеся:" << std::endl;
    for (const auto& discipline : other.disciplines) {
        auto it = std::find_if(result.disciplines.begin(), result.disciplines.end(),
                               [&](const Discipline& d) { return d.id == discipline.id; });
        if (it == result.disciplines.end()) {
            result.addDiscipline(discipline);
        } else {
            std::cout << " - " << discipline.name << " (ID: " << discipline.id << ")" << std::endl;
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
    std::cout << "дублирующиеся:" << std::endl;
    for (const auto& discipline : disciplines) {
        auto it = std::find_if(other.disciplines.begin(), other.disciplines.end(),
                               [&](const Discipline& d) { return d.id == discipline.id; });
        if (it != other.disciplines.end()) {
            result.addDiscipline(discipline);
            std::cout << " - " << discipline.name << " (ID: " << discipline.id << ")" << std::endl;
        }
    }
    return result;
}

void PlanEducation::displayDisciplines() const {
    std::cout << "Список дисциплин в учебном плане:\n";
    for (const auto& discipline : disciplines) {
        std::cout << "ID: " << discipline.id
                  << ", Название: " << discipline.name
                  << ", Тип: " << discipline.type
                  << ", Семестр: " << discipline.semester
                  << ", Итоговый контроль: " << discipline.controlType
                  << ", Общее количество часов: " << discipline.totalHours
                  << ", Лекционные часы: " << discipline.lectureHours
                  << ", Практические часы: " << discipline.practiceHours
                  << ", Курсовая работа: " << (discipline.hasCourseWork ? "Да" : "Нет") << '\n';
    }
}