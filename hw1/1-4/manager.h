#pragma once
#include<iostream>
#include "chef.h"
using namespace std;
class Manager{
    //int num=0;
    //Chef ch[510];
public:
    void newChef(Chef c);
    void order(string dish);
    void order(string dish, int id);
    Manager(){};
};