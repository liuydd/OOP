#include <iostream>
#include <list>
#include <vector>
#include "compare.h"
#include "sortlevel.h"
using namespace std;

Compare<vector<int>> make_comp(list<sort_level> sortlevels)
{
    vector<function<bool(vector<int>,vector<int>)>> comparators;
    for(auto level:sortlevels){
        auto comp=[level](vector<int> left,vector<int> right){
            if(level.order==ASCEND){
                return left[level.column-1]<right[level.column-1];
            }
            else if(level.order==DESCEND){
                return left[level.column-1]>right[level.column-1];
            }
        };
        comparators.push_back(comp);
    };
    return Compare<vector<int>>(comparators);
}
