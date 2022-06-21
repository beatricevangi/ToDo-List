cmake_minimum_required(VERSION 3.14)
project(Laboratory)

set(CMAKE_CXX_STANDARD 14)

add_executable(Laboratory main.cpp Date.cpp Date.h Item.cpp Item.h ToDoList.cpp ToDoList.h)