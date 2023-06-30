#include "Line.h"
using namespace std;

template<typename T>
bool Line<T>::intersect(const Line& l2){
    if(k==l2.k){
        if(b==l2.b) return true;
        else return false;
    }
    return true;
}

template<typename T>
void Line<T>::show(){
    cout<<k<<","<<b<<endl;
}

template<typename T>
bool Line<T>::operator<(const Line& l){
    return k<l.k;
}