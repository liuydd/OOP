#pragma once
#include<iostream>
#include "Line.h"
using namespace std;

template<typename T>
class Point{
    //T x;
    //T y;
public:
    T x;
    T y;
    Point(T x1,T y1):x(x1),y(y1){}
    void move(T dx, T dy);
    void show();
    bool check(Line<T> const& l);
};