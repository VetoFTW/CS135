/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 12
*/

class Money{
    public:
        int dollars;
        int cents;
};

Money add_money(Money x, Money y){
    int totalCents = (x.dollars * 100 + x.cents) + (y.dollars * 100 + y.cents);
    return Money {totalCents / 100, totalCents % 100};
}