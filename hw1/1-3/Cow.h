#pragma once
#include <iostream>
using namespace std;
class Cow{
public:
    Cow(string name,int l, int u, int m);
    Cow(){};
    string name;
    int l;
    int u;
    int m;
    int rest=0;
    int flag=0;
};
Cow::Cow(string name,int l, int u, int m){
    this->name=name;
    this->l=l;
    this->u=u;
    this->m=m;
}