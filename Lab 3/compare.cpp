/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 C
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main(){
    std::string headerLine, placeHolderA, placeHolderB;
    std::string startDate, endDate, date, basinStatus;
    double eastElevation, westElevation;
    bool reachedStartDate = false;

    std::ifstream fin("Current_Reservoir_Levels.tsv");

    if(fin.fail()){
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }

    getline(fin, headerLine);

    std::cout << "Enter starting date: " << std::endl;
    std::cin >> startDate;
    std::cout << "Enter ending date: " << std::endl;
    std::cin >> endDate;
    
    while(fin >> date >> placeHolderA >> eastElevation >> placeHolderB >> westElevation){
        fin.ignore(INT_MAX, '\n');

        if(date == startDate)   reachedStartDate = !reachedStartDate;
        
        if(reachedStartDate){
            basinStatus = eastElevation == westElevation ? " Equal" : eastElevation < westElevation ? " West" : " East";
            std::cout << date << basinStatus << std::endl;
        }

        if(date == endDate) fin.close();
    }

    return 0;
}