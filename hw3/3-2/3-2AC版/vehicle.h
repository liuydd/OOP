#pragma once
#include "wheel.h"
#include "engine.h"
#include <iostream>
class Vehicle{
public:
    Engine e;
    Wheel w;
    void describe();
    Vehicle(int _num,string _name);
    Vehicle();
    /*
    void print();
    void print2();*/
};