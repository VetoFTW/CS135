/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 B
*/

#include <iostream>

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift){
    if(65 <= c && c <= 90){
        if((c + rshift) > 90) c += rshift - 26;
        else c += rshift;
    } else if(97 <= c && c <= 122){
        if((c + rshift) > 122) c += rshift - 26;
        else c += rshift;
    }
    return c;
}

// Caesar cipher encryption
std::string encryptCaesar(std::string plaintext, int rshift){
    for(int i = 0; i < plaintext.length(); i++){
        plaintext[i] = shiftChar(plaintext[i], rshift);
    }
    return plaintext;
}

// Main Function
int main(){

    std::string inputText, shift;

    std::cout << "Enter plaintext: " << std::endl;
    getline(std::cin, inputText, '\n');    
    std::cout << "Enter shift: " << std::endl;
    getline(std::cin, shift, '\n');

    std::cout << encryptCaesar(inputText, std::stoi(shift)) << std::endl;

    return 0;
}