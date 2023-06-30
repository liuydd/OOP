#pragma once
#include "vehicle.h"
#include<iostream>
class Motor:public Vehicle{
public:
    Motor(int _num,string _name);
    void describe();
    void sell();
};