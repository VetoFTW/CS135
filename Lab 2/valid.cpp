/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 A
*/

#include <iostream>
#include <cmath>

int main(){

    int inputNum;
    bool isValidNum;

    std::cout << "Please enter an integer: " << std::endl;
    std::cin >> inputNum;

    isValidNum = 0 < inputNum && inputNum < 100 ? true : false;

    while(!isValidNum){
        std::cout << "Please re-enter: " << std::endl;
        std::cin >> inputNum;
        isValidNum = 0 < inputNum && inputNum < 100 ? true : false;
    }

    std::cout << "Number squared is " << pow(inputNum, 2) << std::endl;

    return 0;
}
