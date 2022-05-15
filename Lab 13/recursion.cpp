/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 12 A B C D E
*/

#include <iostream>

void printRange(int left, int right){
    if(left <= right){
        std::cout << left << " ";
        printRange(left+1, right);
    }
}

int sumRange(int left, int right){
    if(right < left)
        return 0;
    if(left == right)
        return right;
    return left + sumRange(left+1, right);
}

int sumArray(int *arr, int size){
    if(size == 1)   return *arr;
    if(size <= 0)   return 0;
    return *arr + sumArray(arr + 1, size - 1);
}

bool isAlphanumeric(std::string s){
    if(s.length() == 0) return true;
    if(!isalnum(s[0]))  return false;
    return isAlphanumeric(s.substr(1));
}

bool nestedParens(std::string s) {
    // cout << s << endl;
    if (s.length() == 0) return true; 
    if (s.length() % 2 == 1) return false; 

    if (s[0] == '(' && s[s.length() - 1] == ')') 
        return nestedParens(s.substr(1, s.length() - 2));
    return false;
}
