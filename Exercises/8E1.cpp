/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E8.1
*/

#include <iostream>
#include <fstream>

int main(){
    std::string str;
    std::ofstream ofile("hello.txt");
    ofile << "Hello, World!";
    ofile.close();
    std::ifstream ifile("hello.txt");
    getline(ifile, str);
    std::cout << str << std::endl;

}