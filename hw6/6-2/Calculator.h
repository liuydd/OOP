#pragma once
#include<iostream>
#include "PerformStrategy.h"
#include "LevelStrategy.h"
using namespace std;

class Calculator{
    LevelStrategy* m_levelStrategy;
    PerformStrategy* m_perfomStrategy;
public:
    Calculator(LevelStrategy* levelstrategy,PerformStrategy* performstrategy){
        this->m_levelStrategy=levelstrategy;
        this->m_perfomStrategy=performstrategy;
    }
    ~Calculator(){
        delete m_levelStrategy;
        delete m_perfomStrategy;
    }
    int get_base(){
        //cout<<m_levelStrategy->basicbonus<<endl;
        return m_levelStrategy->get_basicbonus();
    }
    int get_total(int base){
        base=get_base();
        return m_perfomStrategy->performstrategy(base);
    }
};