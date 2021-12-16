
#define PI 3.14159265898

#include <iostream>
#include <math.h>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
    // Dynamic - resizeable
    /* Stored on the HEAP
     * Use when you don't know the size
     * OR it can change
     * OR when the .size() > 16 for large matrices (32+)
     */
    MatrixXd d;

    // Fixed size Matrix
    /* Stored on the STACK
     * Use when you know what the size of the matrix is and if it's unchanging
     * Best for when .size() < 16. so 4x4 matrix
     */
    Matrix4d f;
    std::cout << "Size of 4x4 matrix: " << f.size() << std::endl;
    std::cout << "----------------------------------------------\n";

    // RESIZE
    /* For dynamic matrices. You can use .resize(r,c) on fixed but only with original dims
     *
     */
    d.resize(5,4);

    Matrix3d f3;
    // initializing matrix
    f3 << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;

    // random initialization
    f3 = Matrix3d::Random(); // initialize with random values between -1 to 1
    // random initialization for dynamic matrix with no shape yet
    d = MatrixXd::Random(6, 5); // specify the shape of random matrix
    // if Matrix is an integer, will randomly choose from lowest int#->highest int#
    // initialize with constant value
    f3 = Matrix3d::Constant(1.0); // initialize every value with 1.0
    std::cout << "Hello, World! Here is a fixed matrix: \n" << f3 << std::endl;
    std::cout << "----------------------------------------------\n";

    // initialize dynamic matrix with constant value
    d = MatrixXd::Constant(5,5,1.0);
    // defined shape of dynamic matrix
    MatrixXd d4(4,4);
    // for random or constant, must specify shape
    d4 = MatrixXd::Constant(5,5, 4.2);
    std::cout << "Hello, World! Here is a dynamic matrix: \n" << d4 << std::endl;
    std::cout << "----------------------------------------------\n";

    // Make custom fixed sized matrix
    /* dynamic: Matrix<double, Dynamic, Dynamic> == MatrixXd
     * fixed: Matrix<double, 3, 3> == Matrix3d
    */

    // Set all elements to 0
    Matrix3f f4;
    f4.setZero();
    // Set all elements to 1
    f4.setOnes();
    f4 << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
    // You can index matrix like:
    f4(0,0) = 10;
    std::cout << "f4 index 0,0 is: " << f4(0,0) << std::endl;
    std::cout << "----------------------------------------------\n";

    Matrix4f identity(Matrix4f::Identity());
    // OR MatrixXd identity = MatrixXd::Identity(4,4);
    // OR identity.setIdentity(4,4);
    std::cout << "4x4 Identity matrix: \n" << identity << std::endl;
    std::cout << "----------------------------------------------\n";

    // Access parts of a Matrix
    // Rows
    std::cout << "This is row 0 of matrix f4: \n" << f4.row(0) << std::endl;
    // Columns
    std::cout << "This is column 0 of matrix f4: \n" << f4.col(0) << std::endl;
    // Upper left block of f4
    std::cout << "This is the upper left 2x2 matrix in f4: \n" << f4.block(0,0,2,2) << std::endl;
    // .block(start index row, start index col, how many rows to take, how many cols to take)

    Matrix3d Rotation;
    double a = 60.0*PI/180;
    Rotation << cos(a), -sin(a), 0,
                sin(a),  cos(a), 0,
                     0,       0, 1;
    Vector3d Displacement;
    Displacement << 5, 10, 15;
    Matrix4d Transform = Matrix4d::Identity();
    Transform.block(0,0,3,3) = Rotation;
    Transform.block(0,3,3,1) = Displacement;
    std::cout << "Transformation Matrix: \n" << Transform << std::endl;

    // tail
    Transform.col(3).tail(3) << 20, 42, 2;
    std::cout << "Transformation Matrix: \n" << Transform << std::endl;
    std::cout << "----------------------------------------------\n";

    // diagonal matrix
    Vector3d diagonal;
    diagonal << 1, 2, 3;
    Matrix3d diagonal_matrix;
    diagonal_matrix = diagonal.asDiagonal();
    std::cout << "The vector: \n" << diagonal;
    std::cout << "\n As a diagonal matrix is: \n" << diagonal_matrix << std::endl;
    std::cout << "----------------------------------------------\n";

    return 0;
}
