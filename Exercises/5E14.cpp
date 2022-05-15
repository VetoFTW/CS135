/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.14
*/

void sort2(int &a, int &b){
    int temp;
    if(a > b){
        temp = a;
        a = b;
        b = temp;
    }
}