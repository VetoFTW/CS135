/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 7
*/

int max3(int a, int b, int c){
    if(a >= b && a >= c) return a;
    if(b >= c && b >= a) return b;
    if(c >= a && c >= b) return c;
}