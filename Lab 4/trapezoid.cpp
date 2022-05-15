/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 4 F
*/

#include <iostream>

int main(){

    int width, height, spaces = 0;

    std::cout << "Input width: " << std::endl;
    std::cin >> width;
    std::cout << "Input height: " << std::endl;
    std::cin >> height;

    if((width % 2 == 1 && !(height * 2 - 1 <= width)) || (width % 2 == 0 && height * 2 >= width))
        std::cout << "Impossible shape!" << std::endl;
    else
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(j < spaces)  std::cout << ' ';
                else            std::cout << '*';
            }
            width -= 1;
            spaces += 1;
            std::cout << '\n';
        }
    return 0;
}
