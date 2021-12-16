//
// Created by Lukasz Nowakowski on 2021-12-15.
//

#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main() {

    // Matrix Addition - element wise addition
    Matrix3d a; a << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    Matrix3d b; b << 10, 11, 12, 13, 14, 15, 16, 17, 18;

    std::cout << "a(3,3) + b(3,3): \n" << a+b << std::endl;
    std::cout << "a(3,3) - b(3,3): \n" << a-b << std::endl;
    std::cout << "----------------------------------------------\n";

    // Scalar multiplication
    std::cout << "10*a: \n" << 10*a << std::endl;
    std::cout << "----------------------------------------------\n";

    // Matrix<float, M, N>
    Matrix<float, 1, 2> m1;
    m1 << 1, 2;
    Matrix<float, 2, 2> m2;
    m2 << 1, 2,
        3, 4;
    // Matrix Multiplaction must be MxN * NxANY
    MatrixXf m3 = m1 * m2;
    std::cout << "Result of m1 * m2 is: " << m3 << std::endl;
    std::cout << "----------------------------------------------\n";

    // Vectors have only 1 column
    VectorXf v1(2);
    v1 << 1, 2;
    MatrixXf m4 = m2*v1;
    std::cout << "Result of m2 * v1 is: " << m4 << std::endl;
    std::cout << "----------------------------------------------\n";

    // transpose
    /* just .transpose() will NOT change the matrix
     * it will only output the transpose of itself for that line
     *
     * .transposeInPlace() will change the matrix
     *
     */
    MatrixXf m5 = v1.transpose() * m2;
    std::cout << "Result of v1 * m2 is: " << m5 << std::endl;
    std::cout << "----------------------------------------------\n";

    // inverse
    MatrixXf m6 = m2.inverse();
    std::cout << "The inverse of m2 is: \n" << m6 << std::endl;
    std::cout << "m2*m2^-1:\n" << m2*m6 << std::endl;
    std::cout << "----------------------------------------------\n";

    // How to do non-linear algebra on matrix
    /* Eigen::exp()
     * Eigen::sin()
     * Eigen::asin()
     * Eigen::tan()
     *  ...
     *  but must convert the matrix to array first with 'matrix.array()'
     */
    // Add a constant to each element
    MatrixXf m7 = m1.array()+1;
    std::cout << "Adding 1 to all m1 elements " << m7 << std::endl;
    std::cout << "----------------------------------------------\n";


    return 0;
}