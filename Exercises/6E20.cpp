/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.20
*/

#include <vector>
#include <algorithm>
using std::vector;

vector<int> merge_sorted(vector<int> a, vector<int> b){
    vector<int> mergedList = a;
    for(auto element : b)
        mergedList.push_back(element);
    std::sort(mergedList.begin(), mergedList.end());
    return mergedList;
}

