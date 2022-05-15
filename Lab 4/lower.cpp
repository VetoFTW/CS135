/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 D
*/

#include <iostream>

int main(){

    int length;

    std::cout << "Input side length: " << std::endl;
    std::cin >> length;

    for(int i = 0; i < length; i++){
        for(int j = 0; j <= i; j++)
            std::cout << '*';
        std::cout << '\n';
    }
    return 0;
}