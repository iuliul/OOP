cmake_minimum_required(VERSION 3.21)
project(Lab7_8)

set(CMAKE_CXX_STANDARD 14)

include_directories(Domain)
include_directories(Repository)
include_directories(Service)
include_directories(UserInterface)

add_executable(Lab7_8
        Domain/Expense.cpp
        Domain/Expense.h
        Repository/Repository.cpp
        Repository/Repository.h
        Tests/Tests.cpp
        Tests/Tests.h
        app.cpp
        Service/Service.cpp
        Service/Service.h UserInterface/UI.cpp UserInterface/UI.h)
