/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 B
*/

#include <iostream>

int main(){

    int lowerBound, upperBound;

    std::cout << "Please enter L: " << std::endl;
    std::cin >> lowerBound;
    std::cout << "Please enter U: " << std::endl;
    std::cin >> upperBound;

    for(int i = lowerBound; i < upperBound; i++)
        std::cout << i << std::endl;

    return 0;
}