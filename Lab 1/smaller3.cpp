/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 1 B
*/

#include <iostream>

int main(){

    int firstNumber, secondNumber, thirdNumber, smallestNumber;

    std::cout << "Enter the first number: " << std::endl;
    std::cin >> firstNumber;

    std::cout << "Enter the second number: " << std::endl;
    std::cin >> secondNumber; 

    std::cout << "Enter the third number: " << std::endl;
    std::cin >> thirdNumber; 

    if(firstNumber < secondNumber){
        smallestNumber = firstNumber;
    } else {
        smallestNumber = secondNumber;
    }

    if(thirdNumber < smallestNumber){
        smallestNumber = thirdNumber;
    }

    std::cout << "The smaller of the three is " << smallestNumber;

    return 0;
}