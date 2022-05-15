/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E2.10
*/

#include <iostream>

int main(){

    double gallonsInTank, fuelEfficiency, pricePerGallon;

    std::cin >> gallonsInTank >> fuelEfficiency >> pricePerGallon;

    std::cout << 100 * pricePerGallon / fuelEfficiency << std::endl;
    std:: cout << gallonsInTank * fuelEfficiency << std::endl;

    return 0;
}