/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12 C
*/

#include <vector>
using std::vector;

void gogeta(vector<int> &goku, vector<int> &vegeta){
    for(int i = 0; i < vegeta.size(); i++)
        goku.push_back(vegeta[i]);
    vegeta.clear();
}