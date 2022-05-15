/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 A
*/

#include <iostream>

int main(){

    int boxWidth, boxHeight;

    std::cout << "Input width: " << std::endl;
    std::cin >> boxWidth;
    std::cout << "Input height: " << std::endl;
    std::cin >> boxHeight;

    std::cout << "Shape:" << std::endl;

    for(int i = 0; i < boxHeight; i++){
        for(int j = 0; j < boxWidth; j++)
            std::cout << "*";
        std::cout << '\n';
    }

    return 0;
}