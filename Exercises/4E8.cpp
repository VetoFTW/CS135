/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E4.8
*/

#include <iostream>

int main(){
    std::string input;
    std::cin >> input;

    for(int i = 0; i < input.length(); i++)
        std::cout << input[i] << std::endl;
    
}