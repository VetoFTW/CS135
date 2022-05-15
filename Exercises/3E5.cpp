/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E3.5
*/

#include <iostream>

int main(){

    int a, b, c;
    std::cin >> a >> b >> c;

    if(a < b && a < c && b < c)         std::cout << "increasing" << std::endl;
    else if(a > b && a > c && b > c)    std::cout << "decreasing" << std::endl;
    else                                std::cout << "neither" << std::endl;

}