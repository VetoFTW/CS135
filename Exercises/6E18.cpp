/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E6.18
*/

#include <vector>
using std::vector;

vector<int> append(vector<int> a, vector<int> b){
   for(int i = 0; i < b.size(); i++)
       a.push_back(b[i]);  
   return a;
}

