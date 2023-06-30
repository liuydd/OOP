#include "car.h"
#include <iostream>
using namespace std;
Car::Car(int _num,string _name):Vehicle(_num,_name){
    /*
    if(_num>1)
        cout<<"Finish building a car with "<<_num<<" wheels and a "<<_name<<" engine."<<endl;
    else
        cout<<"Finish building a car with "<<_num<<" wheel and a "<<_name<<" engine."<<endl;
        */
}

void Car::describe(){
    //if(w.get_num()>1)
        cout<<"Finish building a car with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
   // else
        //cout<<"Finish building a car with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
    //if(w.get_num()>1)
        cout<<"A car with "<<w.get_num()<<" wheels and a "<<e.get_name()<<" engine."<<endl;
    //else
       // cout<<"A car with "<<w.get_num()<<" wheel and a "<<e.get_name()<<" engine."<<endl;
}
