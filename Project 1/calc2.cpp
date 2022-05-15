/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 1 C
*/

#include <iostream>

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