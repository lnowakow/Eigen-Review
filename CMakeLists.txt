cmake_minimum_required(VERSION 3.21)
project(Eigen_Review)

set(CMAKE_CXX_STANDARD 17)

find_package(Eigen3 3.3 NO_MODULE)
include_directories(${EIGEN_INCLUDE_DIR})
# Initialization
add_executable(MatrixInit MatrixInitialization.cpp)
target_link_libraries(MatrixInit Eigen3::Eigen)
# Arithmetic
add_executable(Arithmetic MatrixArithmetic.cpp)
target_link_libraries(Arithmetic Eigen3::Eigen)
# Transformations
add_executable(Transforms Transforms.cpp)
target_link_libraries(Transforms Eigen3::Eigen)
