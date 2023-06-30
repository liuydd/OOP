#pragma once
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class MyQueriable{
    vector<T> arr;
public:
    MyQueriable(vector<T> _arr):arr(_arr){}
    T& operator[](int index){return arr[index];}
    int size(){return arr.size();}
    T sum(){
        T s=0;
        for(int i=0;i<arr.size();i++)
            s+=arr[i];
        return s;
    }
    template<class func>
    MyQueriable<T> where(func f){
        vector<T> arr_output;
        for(int i=0;i<arr.size();i++){
            if(f(arr[i])) arr_output.push_back(arr[i]);
        }
        return arr_output;
    }
    template<class func>
    MyQueriable<T> apply(func f){
        vector<T> arr_output;
        for(int i=0;i<arr.size();i++){
            arr_output.push_back(f(arr[i]));
        }
        return arr_output;
    }
};

template<typename T>
MyQueriable<T> from(vector<T> arr){
    return MyQueriable<T>(arr);
}