/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 6
*/

#include <iostream>

int main(){
    for(unsigned int i = 0; i < 6; i++){
        for(unsigned int j = 0; j < 5; j++){
            if(j < 4)   std::cout << "* ";
            else        std::cout << '*';
        }
        std::cout << '\n';
    }
}