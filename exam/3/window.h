#pragma once
#include <memory>
#include <list>
#include "event.h"

using namespace std;

class Window;

class Widget {
    string _name;
    Window* _parent;
public:
    Widget(string name) :_name(name), _parent(nullptr) {}
    string getName() const { return _name; }
    Window* getParent() const { return _parent; }
    void setParent(Window * parent) {_parent = parent;}
    virtual ~Widget() {}
};

class Button :public Widget, public Click, public DoubleClick {
public:
    Button(string name) :Widget(name) {}
};

class Checkbox :public Widget, public Click {
    //bool is_chose=false;
public:
    bool is_chose=false;
    Checkbox(string name) :Widget(name) {}
    void click(){
        if(is_chose) is_chose=false;
        else is_chose=true;
    }
};

class Window {

private:
    list<shared_ptr<Widget>> Widgets;
    // TODO

public:
    // TODO
    shared_ptr<Widget> getPointerByName(string name){
        return make_shared<Widget>(name);
    }
    // TODO
    Widget& getElementByName(string name){
        auto p=make_shared<Widget>(name);
        //return &p;
    }
    // TODO
    bool addElement(shared_ptr<Widget> w){
        for(auto wid:Widgets){
            if(w->getName()==wid->getName())
                return false;
        }
        Widgets.push_back(w);
        return true;
    }
    // TODO
    bool undo(){}
};
