cmake_minimum_required(VERSION 3.29)
project(Fedorin)

set(CMAKE_CXX_STANDARD 14)

include_directories(lab1)

add_executable(Fedorin
    lab1/accm.cpp
    lab1/accm.h
    lab1/atmElementManagement.cpp
    lab1/atmSystemControls.h
    lab1/ca.cpp)
