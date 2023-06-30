#include<iostream>
#include<vector>
#include "C:/Users/ultrarealistic/Desktop/eigen-master/Eigen/Dense"  //这里可以改成#include <Eigen/Dense>或自己本地的地址
#include "C:/Users/ultrarealistic/Desktop/eigen-master/Eigen/Sparse"  //同上
using namespace std;

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::Triplet<double> Trip;

int main(){
        //设置Triplet列表，该列表可以表示稀疏矩阵
		vector<Trip> tripletList(9);
		tripletList.push_back(Trip(0, 0, 1));
		tripletList.push_back(Trip(0, 1, -2));
		tripletList.push_back(Trip(0, 2, -2));
		tripletList.push_back(Trip(1, 0, -2));
		tripletList.push_back(Trip(1, 1, 1));
		tripletList.push_back(Trip(1, 2, -1));
		tripletList.push_back(Trip(2, 0, -2));
		tripletList.push_back(Trip(2, 1, -1));
		tripletList.push_back(Trip(2, 2, 3));
		
		//用Triplet列表构造稀疏矩阵
		SpMat mat(3, 3);
		mat.setFromTriplets(tripletList.begin(), tripletList.end());
		
		//使用Cholesky分解矩阵并求解x
		Eigen::SimplicialLDLT<SpMat> chol(mat); 
        Eigen::Matrix<double, 3, 1> b;
        b = Eigen::MatrixXd::Random(3, 1);
		Eigen::MatrixXd x = chol.solve(b);
		
		//输出结果
        cout << "x is: "<< x.transpose()<<endl;
    return 0;
}