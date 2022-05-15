/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12 D
*/

#include <iostream>
#include <vector>
using std::vector;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2){
    vector<int> myList((v1.size() > v2.size() ? v1.size() : v2.size()), 0);

    for(unsigned int i = 0; i < v1.size(); i++)
        myList[i] += v1[i];
    for(unsigned int i = 0; i < v2.size(); i++)
        myList[i] += v2[i];

    return myList;
}