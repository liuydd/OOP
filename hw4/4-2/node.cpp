#include "node.h"
#include <iostream>
using namespace std;

void PlaceholderNode::set_val(float val){
    this->value_=val;
}

void PlaceholderNode::calc() {

}

Node::~Node(){}