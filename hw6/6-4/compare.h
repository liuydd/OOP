#pragma once
#include<iostream>
#include<vector>
#include<functional>
#include <initializer_list>
using namespace std;

template<typename T>
class Compare {
    //initializer_list<function<bool(T,T)>> comparators_;
    vector <function<bool(T,T)>> comparators_;
public:
    Compare(initializer_list<function<bool(T,T)>> comparators) : comparators_(comparators) {}
    Compare(vector<function<bool(T,T)>> comparators) : comparators_(comparators) {}
    bool operator()(const T& left, const T& right) const {
        for (auto comp : comparators_) {
            if (comp(left, right)) {
                return true;
            } else if (comp(right, left)) {
                return false;
            }
        }
        return false;
    } 
};

/*
template<typename T>
class Compare{
    bool xcomp(T a, T b);
    bool xcomp(T a, T b);
    bool xcomp(T a, T b);
    initializer_list<bool> list={xcomp,ycomp,zcomp};
public:
    Compare(initializer_list<bool> lst):list(lst){
        this->xcomp()=lst[0];
        this->ycomp()=lst[1];
        this->zcomp()=lst[2];
    }
    bool operator()(T _a,T _b){
        
    }
};
*/
