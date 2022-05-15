/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 G
*/

#include <iostream>

int main(){

    int width, height;
    bool isAstriskTurnRow = false, isAstriskTurnCol = false;;
    std::string checkerPatternLine = "";

    std::cout << "Input width: " << std::endl;
    std::cin >> width;
    std::cout << "Input height: " << std::endl;
    std::cin >> height;

    std::cout << "Shape:" << std::endl;

    for(int i = 1; i <= height; i++){
        
        if(i % 3 == 0) 
            isAstriskTurnCol = !isAstriskTurnCol;
        
        for(int j = 0; j < width; j++){
            if(j % 3 == 0) isAstriskTurnRow = !isAstriskTurnRow;
            if(isAstriskTurnRow) std::cout << '*';
            else std::cout << ' ';
        }
        std::cout << '\n';

        if(isAstriskTurnCol) isAstriskTurnRow = true;
        else isAstriskTurnRow = false;

    }

    return 0;
}