/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 5
*/

#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream file("data.txt");
    std::string temp;
    while(std::getline(file, temp, '\n'))
        std::cout << temp << '\n';
    file.close();
}