/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12 A
*/

#include <vector>
using std::vector;

vector<int> makeVector(int n){
    vector<int> myVector;
    for(int i = 0; i < n; i++)
        myVector.push_back(i);
    return myVector;
}