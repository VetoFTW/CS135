/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 A
*/

#include <iostream>

int main(){

    int sumOfNumbers = 0, inputNumber;

    while(std::cin >> inputNumber){
        sumOfNumbers += inputNumber;
    }

    std::cout << sumOfNumbers << std::endl;

    return 0;
}