/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.15
*/

void sort3(int &a, int &b, int &c){
    int temp;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
    if(b > c){
        temp = b;
        b = c;
        c = temp;
    }
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
}