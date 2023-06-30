#pragma once
#include "vehicle.h"
class Car:public Vehicle{
public:
    Car(int _num,string _name);
    void describe();
};