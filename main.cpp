
#include <iostream>
#include <eigen3/Eigen/Dense>

int main() {
    Eigen::MatrixXd mat(4,4);

    mat << 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1;

    std::cout << "Hello, World! Here is a matrix: \n" << mat << std::endl;
    return 0;
}
