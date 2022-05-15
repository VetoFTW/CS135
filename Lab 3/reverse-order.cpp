/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 3 D
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

int main(){

    std::string headerLine, placeHolderA, placeHolderB, placeHolderC;
    std::string startDate, endDate, date, westElevation;
    std::string myArr[365][2];
    bool startRecording = false, reachedStartDate = false;

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
    
    int i = 0;
    while(fin >> date >> placeHolderA >> placeHolderB >> placeHolderC >> westElevation){
        fin.ignore(INT_MAX, '\n');

        if(date == startDate)
            startRecording = !startRecording;

        if(startRecording){
            myArr[i][0] = date;
            myArr[i][1] = westElevation;
            i += 1;
        }
        if(date == endDate){
            fin.close();
            i -= 1;
        }
    }

    for(int j = i; j >= 0; j--)
        std::cout << myArr[j][0] << " " << myArr[j][1] << " " << "ft" << std::endl;

    return 0;
}