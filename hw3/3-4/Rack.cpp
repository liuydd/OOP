#include "Rack.h"
#include<algorithm>
using namespace std;

Rack::Rack() {}

Rack& Rack::operator+=(int item) {
    rack.push_back(item);
    return *this;
}

Rack& Rack::operator+=(const Rack& other) {
    rack.insert(rack.end(), other.rack.begin(), other.rack.end());
    return *this;
}

ostream& operator<<(ostream& os, const Rack& r) {
    os<<" ";
    for (int item : r.rack) {
        os << item << " ";
    }
    return os;
}

bool Rack::operator<(const Rack& other) const {
    return rack.size() < other.rack.size();
}

bool Rack::operator>(const Rack& other) const {
    return rack.size() > other.rack.size();
}

bool Rack::operator==(const Rack& other) const {
    return rack.size() == other.rack.size();
}

Rack Rack::operator&(const Rack& other) const {
    /*
    Rack result;
    for (int item : rack) {
        if (find(other.rack.begin(), other.rack.end(), item) != other.rack.end()) {
            result += item;
        }
    }
    return result;*/
    Rack temp;
    int flag=0;
    for(int i=0;i<rack.size();i++){
        for(int j=0;j<other.rack.size();j++){
            if(this->rack[i]==other.rack[j]){
                flag=0;
                for(int k=0;k<temp.rack.size();k++){
                    if(this->rack[i]==temp.rack[k])
                        flag=1;
                }
                if(flag==0)
                    temp+=this->rack[i];    
            }     
        }
    }
    return temp;
}

int Rack::operator()(int num) const {
    int count = 0;
    for (int item : rack) {
        if (item == num) {
            count++;
        }
    }
    return count;
}

void Rack::operator~() {
    reverse(rack.begin(), rack.end());
}

void Rack::operator--(int) { 
    rack.pop_back();
}

void Rack::operator--() {
    rack.erase(rack.begin());
}

Rack Rack::operator,(const Rack& other){ //这里也不能变！
    Rack temp=*this;
    temp+=other;
    return temp;
}

Rack Rack::operator,(int a){
    *this+=a;
    return *this;
}

Rack operator,(int a,const Rack& other){ //other不能变！
    //other.rack.insert(other.rack.begin(),a);
    Rack temp=other;
    temp.rack.insert(temp.rack.begin(),a);
    return temp;
}