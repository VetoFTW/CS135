/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 A
*/

#include <iostream>

int main(){

    std::string inputString;

    std::cout << "Input: " << std::endl;
    getline(std::cin, inputString);

    for(int i = 0; i < inputString.length(); i++)
        std::cout << inputString[i] << " " << (int) inputString[i] << std::endl;

    return 0;
}