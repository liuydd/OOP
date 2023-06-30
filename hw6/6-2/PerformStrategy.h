#pragma once
#include<iostream>
#include<cmath>
using namespace std;

class PerformStrategy{
public:
    double perform;
    virtual int performstrategy(int bonus)=0;
};

class sPerformStrategy:public PerformStrategy{
public:
    double perform;
    sPerformStrategy(double _perform):perform(_perform){}
    int performstrategy(int bonus){
        return floor(bonus+1000);
    }
};

class mPerformStrategy:public PerformStrategy{
public:
    double perform;
    mPerformStrategy(double _perform):perform(_perform){}
    int performstrategy(int bonus){
        return floor(bonus*perform+bonus);
    }
};

class lPerformStrategy:public PerformStrategy{
public:
    double perform;
    lPerformStrategy(double _perform):perform(_perform){}
    int performstrategy(int bonus){
        return floor(bonus+2*perform*bonus);
    }
};
