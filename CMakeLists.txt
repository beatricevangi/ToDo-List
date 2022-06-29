cmake_minimum_required(VERSION 3.14)
project(Laboratory)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(test)

set(SOURCE_FILES Laboratory main.cpp Date.cpp Date.h Item.cpp Item.h ToDoList.cpp ToDoList.h)
add_executable(Laboratory main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Laboratory core)