#include "vehicle.h"
#include<iostream>
using namespace std;
Vehicle::Vehicle(int _num,string _name):e(_name),w(_num){
    if(w.get_num()>1)
        cout<<"Finish building a vehicle with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
    else
        cout<<"Finish building a vehicle with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
}

void Vehicle::describe(){
    
    if(w.get_num()>1)
        cout<<"A vehicle with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
    else
        cout<<"A vehicle with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
}