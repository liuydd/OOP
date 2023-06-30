#pragma once
#include<iostream>
using namespace std;

class Vehicle{
    int max_wheel_num;
    int max_wing_num;
    int wheel=0;
    int wing=0;
public:
    void add_wing(){wing++;}
    void add_wheel(){wheel++;}
    bool finished(){
        return((max_wheel_num==wheel)&&(max_wing_num==wing));
    }
    virtual void run(){cout<<"I am running"<<endl;}
    Vehicle(){
        set_max_wheel_num(0);
        set_max_wing_num(0);
    }
    void set_max_wheel_num(int x){max_wheel_num=x;}
    void set_max_wing_num(int x){max_wing_num=x;}
};