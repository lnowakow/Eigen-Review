cmake_minimum_required(VERSION 3.21)
project(Eigen_Review)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 REQUIRED)

add_executable(Eigen_Review main.cpp)
