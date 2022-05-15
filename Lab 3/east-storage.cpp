/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 A
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>


int main(){

    std::string targetDate, headerLine, date, eastBasinStorage;

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    std::cout << "Enter date: " << std::endl;
    std::cin >> targetDate;

    getline(fin, headerLine);

    while(fin >> date >> eastBasinStorage){
        fin.ignore(INT_MAX, '\n');
        if(targetDate == date){
            std::cout << "East basin storage: " << eastBasinStorage << " billion gallons" << std::endl;
            fin.close();
        }
    }
}