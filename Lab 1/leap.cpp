/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 1 C
*/

#include <iostream>

int main(){

    int userInputYear;

    std::cout << "Enter Year: " << std::endl;
    std::cin >> userInputYear;

    if(userInputYear % 4 != 0){
        std::cout << "Common year" << std::endl;
    } else if(userInputYear % 100 != 0){
        std::cout << "Leap year" << std::endl;
    } else if(userInputYear % 400 != 0){
        std::cout << "Common year" << std::endl;
    } else{
        std::cout << "Leap year" << std::endl;
    }

    return 0;
}