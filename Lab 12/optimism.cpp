/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12 B
*/

#include <iostream>
#include <vector>
using std::vector;

vector<int> goodVibes(vector<int> v){
    vector<int> myList;
    for(int i = 0; i < v.size(); i++)
        if(v[i] >= 0)
            myList.push_back(v[i]);
    return myList;
}