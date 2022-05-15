/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 C
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

// letter - 1 = rshift
std::string encryptVigenere(std::string text, std::string keyword){
    int counter = 0;
    for(int i = 0; i < text.length(); i++)
        if(isalpha(text[i])){
            if(counter == keyword.length()) counter = 0;
            text[i] = shiftChar(text[i], keyword[counter] - 97);
            counter++;
        }  
    return text;
}

int main(){

    std::string inputText, keyWord;

    std::cout << "Enter plaintext: " << std::endl;
    getline(std::cin, inputText, '\n');
    std::cout << "Enter keyword: " << std::endl;
    getline(std::cin, keyWord, '\n');

    std::cout << encryptVigenere(inputText, keyWord) << std::endl;

    return 0;
}