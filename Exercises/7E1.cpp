/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E5.14
*/

#include <iostream>

void sort2(double* p, double* q){
    double temp;
    if(*p > *q){
        temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main(){
    double a, b;
    std::cin >> a >> b;
    sort2(&a, &b);
    std::cout << a << " " << b << std::endl;
}