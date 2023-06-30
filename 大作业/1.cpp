#include<iostream>
#include "C:/Users/ultrarealistic/Desktop/eigen-master/Eigen/Dense"  //这里可以改成#include <Eigen/Dense>或自己本地的地址
using namespace std;
using Eigen::MatrixXd;

int main(){
    //声明一个2行3列的矩阵
    MatrixXd m1(2,3);
    m1 << 1, 2, 3, 4, 5, 6;
    //声明一个3行2列的矩阵
    MatrixXd m2(3,2);
    m2 << 1, 2, 2, 3, 0, 4;
    //声明一个3行2列的矩阵
    MatrixXd m3(3,2);
    m3 << 2, 0, 7, 1, 0, 3;
    //打印m1, m2, m3
    cout<<"m1 = "<<endl<<m1<<endl;
    cout<<"m2 = "<<endl<<m2<<endl;
    cout<<"m3 = "<<endl<<m3<<endl;
    //计算m2+m3, m2-m3, m1*m2
    cout<<"m2 + m3"<<endl<<m2+m3<<endl;
    cout<<"m2 - m3"<<endl<<m2-m3<<endl;
    cout<<"m1 * m2"<<endl<<m1*m2<<endl;
    return 0;
}
