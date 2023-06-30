#include<iostream>
#include "chef.h"
using namespace std;
Chef::Chef(string _name, string _signatureDish){
    this->name=_name;
    this->signatureDish=_signatureDish;
}
bool Chef::isSignatureDish(string dish){
    if(dish==signatureDish)
        return true;
    else
        return false;
}
void Chef::cook(string dish){
    if(isSignatureDish(dish))
        cout<<name<<" made an awesome "<<dish<<endl;
    else
        cout<<name<<" made a plain "<<dish<<endl;
}