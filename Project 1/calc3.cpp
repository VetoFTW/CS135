/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 D
*/

#include <iostream>
#include <cmath>

int main(){

    char inputStream;
    int calcSum = 0;
    std::string numberAssembler;
    
    while(std::cin >> inputStream){
        if(inputStream != ';'){
            if(inputStream == '+' || inputStream == '-'){
                calcSum += std::stoi(numberAssembler);
                numberAssembler.clear();
                numberAssembler += inputStream;
            } else if(inputStream == '^'){
                numberAssembler = std::stoi(numberAssembler) >= 0 ? std::to_string(pow(std::stoi(numberAssembler), 2)) : std::to_string(pow(std::stoi(numberAssembler), 2) * -1);
            } else{
                numberAssembler += inputStream;
            } 
        } else{
            calcSum += std::stoi(numberAssembler);
            std::cout << calcSum << std::endl;
            calcSum = 0;
            numberAssembler = "";
        }
    }

    return 0;
}