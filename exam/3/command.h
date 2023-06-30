#pragma once
#include "window.h"
#include <iostream>
#include <memory>
#include <list>
using namespace std;

class ClearAll {
    // TODO
    list<shared_ptr<Checkbox>> box;
public:
    // TODO
    ClearAll(list<shared_ptr<Checkbox>> checkbox):box(checkbox){}
    void operator()(){
        for(auto a:box){
            a->is_chose=false;
        }
    }
};

class SelectAll {
    // ...
    list<shared_ptr<Checkbox>> box;
public:
    // TODO
    SelectAll(list<shared_ptr<Checkbox>> checkbox):box(checkbox){}
    void operator()(){
        for(auto a:box){
            a->is_chose=true;
        }
    }
};

class Submit {
    // ...
    list<shared_ptr<Checkbox>> box;
public:
    // TODO
    Submit(list<shared_ptr<Checkbox>> checkbox):box(checkbox){}
    void operator()(){
        for(auto a:box){
            if(a->is_chose) cout<<a->getName()<<" is selected"<<endl;
            else cout<<a->getName()<<" is not selected"<<endl;
        }
    }
};