#pragma once
#include<iostream>
using namespace std;

class LevelStrategy{
public:
    virtual int get_basicbonus()=0;
};

class P1LStrategy:public LevelStrategy{
public:
    int get_basicbonus(){return 2000;}
};

class P2LStrategy:public LevelStrategy{
public:
    int get_basicbonus(){return 5000;}
};

class P3LStrategy:public LevelStrategy{
public:
    int get_basicbonus(){return 10000;}
};