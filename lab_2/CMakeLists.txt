cmake_minimum_required(VERSION 3.16)
project(lab_2)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab_2 source.cpp)
target_link_libraries(lab_2 ${OpenCV_LIBS})