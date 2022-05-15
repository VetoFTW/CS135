/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 B
*/

#include <iostream>

int main(){

    int boxWidth, boxHeight;
    bool isAstriskTurn = true;

    std::cout << "Input width: " << std::endl;
    std::cin >> boxWidth;
    std::cout << "Input height: " << std::endl;
    std::cin >> boxHeight;

    std::cout << "Shape:" << std::endl;

    for(int i = 0; i < boxHeight; i++){

        if(i % 2 == 0)  isAstriskTurn = true;
        else            isAstriskTurn = false;
        
        for(int j = 0; j < boxWidth; j++){
            if (isAstriskTurn)  std::cout << "*";
            else                std::cout << " ";
            isAstriskTurn = !isAstriskTurn;
        }

        std::cout << '\n';
    }
    
    return 0;
}