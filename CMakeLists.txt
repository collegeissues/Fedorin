cmake_minimum_required(VERSION 3.29)
project(Fedorin)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab1)

add_executable(Fedorin
    lab3/Discipline.h
    lab3/PlanEducation.h
    lab3/PlanEducation.cpp
    lab3/main.cpp
        lab3/main.cpp
        lab4/Real.cpp
        lab4/Real.h
        lab4/Number.cpp
        lab4/Number.h
        lab4/MenuDrawer.cpp
        lab4/MenuDrawer.h
)