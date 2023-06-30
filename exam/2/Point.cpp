#include "Point.h"
using namespace std;
#include "Line.h"
template<typename T>
void Point<T>::move(T dx, T dy){
    x+=dx;
    y+=dy;
}

template<typename T>
void Point<T>::show(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}

template<typename T>
bool Point<T>::check(Line<T> const& l){
    return (y-l.k*x-l.b)==0;
}