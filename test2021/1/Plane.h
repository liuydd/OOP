#include<iostream>
#include"Vehicle.h"
using namespace std;

class Plane: public Vehicle { 
    public:
        void run(){cout<<"I am running and flying"<<endl;}
        Plane() {
            set_max_wheel_num(3);
            set_max_wing_num(2);
        }
};