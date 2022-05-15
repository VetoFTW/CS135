/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 B
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main(){

    std::string headerLine, date;
    double eastBasinStorage, minValue = 100, maxValue = 0;

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    getline(fin, headerLine);

    while(fin >> date >> eastBasinStorage){
        fin.ignore(INT_MAX, '\n');

        if(eastBasinStorage > maxValue) maxValue = eastBasinStorage;
        if(eastBasinStorage < minValue) minValue = eastBasinStorage;
    }

    std::cout << "minimum storage in East basin: " << minValue << " billion gallons" << std::endl;
    std::cout << "MAXimum storage in East basin: " << maxValue << " billion gallons" << std::endl;

    return 0;
}