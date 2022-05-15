/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 1 D
*/

#include <iostream>

int main(){

    int userInputYear, userInputMonth;
    bool isLeapYear;

    std::cout << "Enter year: " << std::endl;
    std::cin >> userInputYear;
    std::cout << "Enter month: " << std::endl;
    std::cin >> userInputMonth;

    if(userInputYear % 4 != 0){
        isLeapYear = false;
    } else if(userInputYear % 100 != 0){
        isLeapYear = true;
    } else if(userInputYear % 400 != 0){
        isLeapYear = false;
    } else{
        isLeapYear = true;
    }

    if(userInputMonth <= 7){
        if(userInputMonth == 2){
            if(isLeapYear){         
                std::cout << "29 days" << std::endl;
            } else{
                std::cout << "28 days" << std::endl;}
        } else if(userInputMonth % 2 == 0){
            std::cout << "30 days" << std::endl;
        } else{
            std::cout << "31 days" << std::endl;
        }
    } else{
        if(userInputMonth % 2 == 0){
            std::cout << "31 days" << std::endl;
        } else{
            std::cout << "30 days" << std::endl;
        }
    }

    return 0;
}