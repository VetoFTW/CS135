/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 1
*/

#include <iostream>
#include <string>

int main(){
    std::string input;
    getline(std::cin, input);

    for(int i = 0; i <= input.length(); i++){
        std::cout << input.substr(0, i) << std::endl;
    }
    for(int i = input.length()-1; i > 0; i--){
        std::cout << input.substr(0, i) << std::endl;
    }

}