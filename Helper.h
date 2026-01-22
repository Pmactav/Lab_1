//
// Created by Peter on 1/21/2026.
//

#ifndef LAB_1_HELPER_H
#define LAB_1_HELPER_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

MatrixXd ReadDatatoMatrix(const string& filename);
void WriteMatrixToFile(const MatrixXd& Mat, const string& filename, unsigned int precision);
MatrixXd DesignMatrix(const MatrixXd& M, double omega);

#endif //LAB_1_HELPER_H