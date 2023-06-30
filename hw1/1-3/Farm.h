#pragma once
#include <iostream>
#include "Cow.h"
using namespace std;
class Farm{
    double milk=0.0;
    //int n;
public:
    int n;
    int p;
    void addCow(Cow cow);
    void supply(string name, int a);
    void startMeal();
    void produceMilk();
    double getMilkProduction();
    Farm(int n);
    Cow co[110];
};

Farm::Farm(int n){
    this->n=n;
    p=n;
}

void Farm::addCow(Cow cow){
    co[p--]=cow;
}
void Farm::supply(string name, int a){//为什么这个函数进不去呢
    //cout<<n<<endl; 怪，为什么这里的n等于0。问题出在第24行，n的值发生了改变
    for(int i=1;i<=n;i++){
        if(co[i].name==name){
            co[i].rest+=a;
            //cout<<co[i].rest<<endl;
        }
    }
}
void Farm::startMeal(){
    for(int i=1;i<=n;i++){
        if(co[i].rest==0)//产奶量为0
            co[i].flag=0;
        else if(co[i].rest<co[i].l)//产奶量减半
            co[i].flag=1;
        else if(co[i].rest>=co[i].l&&co[i].rest<=co[i].u)//产奶量正常且rest清零
            co[i].flag=2;
        else//产奶量正常且rest减u
            co[i].flag=3;
    }
}
void Farm::produceMilk(){
    for(int i=1;i<=n;i++){
        if(co[i].flag==0)
            milk+=0.0;
        else if(co[i].flag==1){
            milk+=co[i].m/2.0;
            co[i].rest=0;
        }
        else if(co[i].flag==2){
            milk+=co[i].m;
            co[i].rest=0;
        }
        else{
            milk+=co[i].m;
            co[i].rest-=co[i].u;
        }
    }
}
double Farm::getMilkProduction(){
    return milk;
}
