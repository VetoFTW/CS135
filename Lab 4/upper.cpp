/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 E
*/

#include <iostream>

int main(){

    int length;

    std::cout << "Input side length: " << std::endl;
    std::cin >> length;

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j++){
            if(j < i)   std::cout << ' ';
            else        std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}