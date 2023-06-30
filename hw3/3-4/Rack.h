#pragma once
#include <vector>
#include <iostream>
using namespace std;

class Rack {
public:
    Rack();
    Rack& operator+=(int);
    Rack& operator+=(const Rack&);
    friend ostream& operator<<(ostream&, const Rack&);
    bool operator<(const Rack&) const;
    bool operator>(const Rack&) const;
    bool operator==(const Rack&) const;
    Rack operator&(const Rack&) const;
    int operator()(int) const;
    void operator~();
    void operator--(); //前缀
    void operator--(int);
    Rack operator,(const Rack&);
    Rack operator,(int);
    friend Rack operator,(int ,const Rack&);

private:
    vector<int> rack;  // 存储货物和货架
};
