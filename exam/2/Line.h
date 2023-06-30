#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Line{
    //T k;
    //T b;
public:
    T k;
    T b;
    Line(T k1,T b2):k(k1),b(b2){}
    Line(T k1):k(k1),b(0){}
    bool intersect(const Line&);
    void show();
    bool operator<(const Line&);
};