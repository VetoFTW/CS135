/*
Author: Czarnecki, Martin
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 1 A
*/

#include <iostream>

int main(){
    int firstNumber, secondNumber;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> firstNumber;

    std::cout << "Enter the second number: " << std::endl;
    std::cin >> secondNumber; 

    if(firstNumber < secondNumber){
        std::cout << "The smaller of the two is " << firstNumber;
    }else {
        std::cout << "The smaller of the two is " << secondNumber;

    }

    return 0;
}