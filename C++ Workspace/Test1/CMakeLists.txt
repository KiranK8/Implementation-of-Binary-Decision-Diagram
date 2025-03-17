cmake_minimum_required(VERSION 3.20)
project(Test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Test1 Manager.cpp ManagerInterface.h Manager_test.cpp)
