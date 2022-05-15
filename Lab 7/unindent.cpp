/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7 A
*/

#include <iostream>
#include <fstream>

std::string removeLeadingSpaces(std::string line){
    std::string newLine;
    bool locatedFirstChar = false;
    for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i])) locatedFirstChar = true;
        if(locatedFirstChar) newLine += line[i];
    }
    return newLine;
}

int main() {
    std::string line;
    while(getline(std::cin, line, '\n')){
        std::cout << removeLeadingSpaces(line) << std::endl;
    }    
}