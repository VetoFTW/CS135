/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 7 B
*/

#include <iostream>

int countCharInString(std::string line, char character){
    int counter = 0;
    for(int i = 0; i < line.size(); i++)
        counter += line[i] == character ? 1 : 0;
    return counter;
}

std::string removeLeadingSpaces(std::string line){
    std::string newLine;
    bool locatedFirstChar = false;
    for(int i = 0; i < line.length(); i++){
        if(!isspace(line[i])) locatedFirstChar = true;
        if(locatedFirstChar) newLine += line[i];
    }
    return newLine;
}

int main(){
    std::string line,
                newLine;
    int tab = 0;

    while(getline(std::cin, line, '\n')){
        std::string newLine = removeLeadingSpaces(line),
                    tabs = "";

        for(int i = 0; i < (newLine[0] != '}' ? tab : tab - 1 ); i++)
            tabs += '\t';
        
        std::cout << tabs << newLine << std::endl;
        tab += countCharInString(line, '{') - countCharInString(line, '}');
    }
}