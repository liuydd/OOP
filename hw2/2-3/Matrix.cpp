#include<iostream>
#include "Matrix.h"
using namespace std;
Matrix::Matrix(){
    this->col=0;
    this->row=0;
    //this->elem=NULL;
}
Matrix::Matrix(int _row, int _col){
    this->row=_row;
    this->col=_col;
    elem=new int *[row];
    for(int i=0;i<row;i++){
        elem[i]=new int[col];
        for(int j=0;j<col;j++)
            elem[i][j]=0;
    }
}
Matrix::~Matrix(){
    for(int i=0;i<row;i++)
        delete[] elem[i];
    delete[] elem;
}
Matrix Matrix::operator+(const Matrix& m){
    Matrix res(row,col);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                res.elem[i][j]=elem[i][j]+m.elem[i][j];
        return res;
    }
Matrix Matrix::operator-(const Matrix& m){
    Matrix res(row,col);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                res.elem[i][j]=elem[i][j]-m.elem[i][j];
        return res;
    }
Matrix Matrix::operator*(const int a){
    Matrix res(row,col);
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                res.elem[i][j]=elem[i][j]*a;
        return res;
    }
Matrix Matrix::operator*(const Matrix& m){
    Matrix res(row,m.col);       
        for(int i=0;i<row;i++){
            for(int k=0;k<m.col;k++){
                for(int j=0;j<col;j++){
                    res.elem[i][k]+=elem[i][j]*m.elem[j][k];
                }
            }
        }
        return res;
    }
Matrix transpose(const Matrix& m){
    Matrix t(m.col,m.row);
    for(int i=0;i<m.row;i++)
        for(int j=0;j<m.col;j++)
            t.elem[j][i]=m.elem[i][j];
    return t;
}
int* Matrix::operator[](int a) const{
    return elem[a];
}
ostream& operator<<(ostream& out, const Matrix& m){
    for(int i=0;i<m.row;i++){
        for(int j=0;j<m.col;j++)
            out<<m.elem[i][j]<<" ";
        out<<endl;
    }
    return out;
}
istream& operator>>(istream& in, Matrix& m){
    in>>m.row>>m.col;
    //m.elem=new int *[m.col];
    //cout<<m.row<<" "<<m.col<<endl;
    m.elem=new int *[m.row];
    for(int i=0;i<m.row;i++){
        m.elem[i]=new int[m.col];
        for(int j=0;j<m.col;j++)
            m.elem[i][j]=0;
    }
    for(int i=0;i<m.row;i++)
        for(int j=0;j<m.col;j++)
            in>>m.elem[i][j];
    return in;
}