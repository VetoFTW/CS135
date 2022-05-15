/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: E9.3
*/

#include <iostream>

class Circuit{
    private:
        bool lampState = false;
        bool firstSwitchState = false;
        bool secondSwitchState = false;

    public:
        int get_first_switch_state(){
            return firstSwitchState;
        };

        int get_second_switch_state(){
            return secondSwitchState;
        };

        int get_lamp_state(){
            return lampState;
        };

        void toggle_first_switch(){
            firstSwitchState = !firstSwitchState;
            lampState = !lampState;
        };

        void toggle_second_switch(){
            secondSwitchState = !secondSwitchState;
            lampState = !lampState;
        };
};