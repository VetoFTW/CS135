/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 D
*/

#include <iostream>

int main(){

    int myArr[60] = {0, 1};

    for(int i = 0; i < 60; i++){
        if(i != 0 && i != 1)   
            myArr[i] = myArr[i - 1] + myArr[i - 2];
        std::cout << myArr[i] << std::endl;
    }

    return 0;
}