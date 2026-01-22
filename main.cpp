#include <iostream>
#include <string>
#include <Eigen/Dense>
#include "Helper.h"

using namespace std;
using namespace Eigen;

int main() {
    MatrixXd data = ReadDatatoMatrix("lab1_data_2026.txt");
    double omega = numbers::pi*2;
    MatrixXd A = DesignMatrix(data, omega);
    MatrixXd w = -data.col(1);
    MatrixXd N = A.transpose()*A;
    MatrixXd u = A.transpose()*w;
    MatrixXd x0 = MatrixXd::Zero(3,1);
    MatrixXd delta = -N.inverse()*u;
    MatrixXd x_hat = x0 + delta;
    MatrixXd v_hat = A*delta + w;
    double n = data.rows();
    double sigma2 = (v_hat.transpose()*v_hat)(0)/(n-3);
    cout << "Sigma^2 = " << sigma2 << endl;
    MatrixXd Cx = sigma2*N.inverse();
    double sigmaA = sqrt(Cx(0,0));
    double sigmaB = sqrt(Cx(1,1));
    double sigmaC = sqrt(Cx(2,2));
    cout << "SigmaA = " << sigmaA << ", SigmaB = " << sigmaB << ", SigmaC = " << sigmaC <<endl;
    double yA = sigmaA/x_hat(0);
    double yB = sigmaB/x_hat(1);
    double yC = sigmaC/x_hat(2);
    cout << "yA = " << yA << ", yB = " << yB << ", yC = " << yC << endl;
    WriteMatrixToFile(A, "A.txt", 6);
    WriteMatrixToFile(x_hat, "x_hat.txt", 6);
    WriteMatrixToFile(v_hat, "v_hat.txt", 6);
    return 0;
}