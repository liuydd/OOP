#include "motor.h"
#include<iostream>
using namespace std;
Motor::Motor(int _num,string _name):Vehicle(_num,_name){
    /*
    if(_num>1)
        cout<<"Finish building a motor with "<<_num<<" wheels and a "<<_name<<" engine."<<endl;
    else
        cout<<"Finish building a motor with "<<_num<<" wheel and a "<<_name<<" engine."<<endl;
        */
}

void Motor::describe(){
    //if(w.get_num()>1)
        cout<<"Finish building a motor with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
    //else
    //    cout<<"Finish building a motor with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
    //if(w.get_num()>1)
        cout<<"A motor with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
    //else
    //    cout<<"A motor with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
}

void Motor::sell(){
    cout<<"A motor is sold!"<<endl;
}

