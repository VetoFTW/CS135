/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 2 C
*/

#include <iostream>

int main(){

    int myArr[10], inputIndex, inputValue;

    for(int i = 0; i < 10; i++)     
        myArr[i] = 1;
    
    bool isRunning = true;
    for(int i = 0; i < 10; i++) 
        std::cout << myArr[i] << " ";

    while(isRunning){
        std::cout << '\n';

        std::cout << "Input index: " << std::endl;
        std::cin >> inputIndex;
        std::cout << "Input value: " << std::endl;
        std::cin >> inputValue;

        if(inputIndex < 10 && inputIndex >= 0){
            myArr[inputIndex] = inputValue;
        for(int i = 0; i < 10; i++) 
            std::cout << myArr[i] << " ";
        } else{
            std::cout << "Index out of range. Exit." << std::endl;
            isRunning = !isRunning;
        }

    }

    return 0;
}