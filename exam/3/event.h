#pragma once
#include <functional>
using namespace std;

class Click {
private:
    // TODO
    std::function<void()> func;
public:
    // TODO
    Click(){}
    // TODO
    void setClickCommand(std::function<void()> f){
        func=f;
    }
    // TODO
    virtual void click(){
        func();
    }
};
class DoubleClick {
private:
    // TODO
    std::function<void()> func;
public:
    // TODO
    DoubleClick(){}
    // TODO
    void setDoubleClickCommand(std::function<void()> f){
        func=f;
    }
    // TODO
    virtual void doubleClick(){
        func();
    }
};