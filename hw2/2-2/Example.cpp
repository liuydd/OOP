#include <iostream>
#include "Example.h"

using namespace std;

	// (2)
	int Example::num=0;

Example::Example(int data) {
	this->data=data;
	num++;
	id=num;
	cout<<"Example #"<<id<<" is created"<<endl;
	// (3)
}

void Example::getData() {
	//cout<<this->id<<endl;
	cout<<"The data of Example #"<<id<<" is "<<data<<endl;
	// (4)
}

Example::~Example() {
	cout<<"Example #"<<id<<" is destroyed"<<endl;
	//num--;
	// (5)
}