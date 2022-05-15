/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.6
*/

#include <string>

std::string middle(std::string str){
    std::string newStr = "";
    if(str.size() % 2 == 0){
        newStr += str[str.size() / 2 - 1];
        newStr += str[str.size() / 2];
    }
    else
        newStr += str[str.size() / 2];
    return newStr;
}