/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 C
*/

#include <iostream>

int main(){

    int sizeOfCross, astrickDistance = 0;

    std::cout << "Input side length: " << std::endl;
    std::cin >> sizeOfCross;

    for(int i = 0; i < sizeOfCross; i++){
        for(int j = 1; j <= sizeOfCross; j++){
            if(j == 1 + astrickDistance || j == sizeOfCross - astrickDistance)
                std::cout << "*";
            else
                std::cout << " ";
        }
        astrickDistance++;
        std::cout << '\n';
    }
    return 0;
}