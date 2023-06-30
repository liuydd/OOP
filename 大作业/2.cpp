#include<iostream>
#include<cmath>
#include<ctime>
#include "C:/Users/ultrarealistic/Desktop/eigen-master/Eigen/Dense"  //这里可以改成#include <Eigen/Dense>或自己本地的地址
#include "C:/Users/ultrarealistic/Desktop/eigen-master/Eigen/Core"  //同上
using namespace std;
#define MATRIX_SIZE 100

template <typename T, typename F>
void evaluate(const T& A, const T& b, string label) {
    clock_t time_stt = clock();
    F dec(A);
    T x = dec.solve(b);
    T diff = A * x - b;
    cout << "--------- " << label << " ---------"<<endl;
    cout << "Time used: " << 1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    //cout << "x is: "<< x.transpose()<<endl;
    cout << "Loss: " << diff.norm() <<endl;
    cout << "--------- " << label << " ---------"<<endl;
    return;
}

int main(){
    //方程组形式Ax=b，假设A为方阵
    Eigen::Matrix<double, MATRIX_SIZE, MATRIX_SIZE> A;
    A = Eigen::MatrixXd::Random(MATRIX_SIZE, MATRIX_SIZE);  
    Eigen::Matrix<double, MATRIX_SIZE, 1> b;
    b = Eigen::MatrixXd::Random(MATRIX_SIZE, 1);

    //法一：高斯法，直接求矩阵A的逆
    clock_t time_stt = clock();
    Eigen::Matrix<double, MATRIX_SIZE, 1> x1;
    Eigen::Matrix<double, MATRIX_SIZE, 1> diff;
    x1 = A.inverse()*b;
    diff = A * x1 - b;
    cout << "--------- " << "DIRECT INVERSE" << " ---------"<<endl;
    cout<<"Time used: "<<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC<<"ms"<<endl;
    //cout<<"x is "<<x1.transpose()<<endl;
    cout << "Loss: " << diff.norm() <<endl;
    cout << "--------- " << "DIRECT INVERSE" << " ---------"<<endl;

    //法二：LU分解
    evaluate<Eigen::MatrixXd, Eigen::FullPivLU<Eigen::MatrixXd>>(A, b, "FullPivLU");
    evaluate<Eigen::MatrixXd, Eigen::PartialPivLU<Eigen::MatrixXd>>(A, b, "PartialPivLU");

    //法三：QR分解
    evaluate<Eigen::MatrixXd, Eigen::ColPivHouseholderQR<Eigen::MatrixXd>>(A, b, "ColPivHouseholderQR");
    evaluate<Eigen::MatrixXd, Eigen::FullPivHouseholderQR<Eigen::MatrixXd>>(A, b, "FullPivHouseholderQR");
    evaluate<Eigen::MatrixXd, Eigen::HouseholderQR<Eigen::MatrixXd>>(A, b, "HouseholderQR");

    //法三：Cholesky分解
    evaluate<Eigen::MatrixXd, Eigen::LLT<Eigen::MatrixXd>>(A.transpose()*A, A.transpose()*b, "LLT"); //为了满足LLT所需要的正定矩阵
    evaluate<Eigen::MatrixXd, Eigen::LDLT<Eigen::MatrixXd>>(A.transpose()*A, A.transpose()*b, "LDLT");

    return 0;
}

