/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 6 D
*/

#include <iostream>

// A helper function to shift one character by lshift
char shiftChar(char c, int lshift){
    if(65 <= c && c <= 90){
        if((c - lshift) < 65) c -= lshift - 26;
        else c -= lshift;
    } else if(97 <= c && c <= 122){
        if((c - lshift) < 97) c -= lshift - 26;
        else c -= lshift;
    }
    return c;
}

std::string decryptCaesar(std::string plainText, int lshift){
    for(int i = 0; i < plainText.length(); i++)
        plainText[i] = shiftChar(plainText[i], lshift);
    return plainText;
}

std::string decryptVigenere(std::string plainText, std::string keyword){
    int counter = 0;
    for(int i = 0; i < plainText.length(); i++)
        if(isalpha(plainText[i])){
            if(counter == keyword.length()) counter = 0;
            plainText[i] = shiftChar(plainText[i], keyword[counter] - 97);
            counter++;
        }
    return plainText;
}

int main(){

    std::string plainText, keyword, lshift;

    std::cout << "Enter plaintext: " << std::endl;
    getline(std::cin, plainText, '\n');
    std::cout << "= Caesar = " << std::endl;
    std::cout << "Enter shift    : " << std::endl;
    getline(std::cin, lshift, '\n');
    std::cout << "Ciphertext     : " << plainText << std::endl;
    std::cout << "Decrypted      : " << decryptCaesar(plainText, std::stoi(lshift)) << std::endl;

    std::cout << "Enter plaintext: " << std::endl;
    getline(std::cin, plainText, '\n');
    std::cout << "= Vigenere = " << std::endl;
    std::cout << "Enter keyword  : " << std::endl;
    getline(std::cin, keyword, '\n');
    std::cout << "Ciphertext     : " << plainText << std::endl;
    std::cout << "Decrypted      : " << decryptVigenere(plainText, keyword) << std::endl;
        
    return 0;
}