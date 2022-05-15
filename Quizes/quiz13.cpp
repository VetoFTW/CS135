/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 13
*/

#include <string>

class Customer {
    private:
        std::string name;
        std::string unique_id;
    public:
        Customer(std::string name, std::string unique_id){
            this->name = name;
            this->unique_id = unique_id;
        }
        Customer(){
            name = "";
            unique_id = "";
        }

        std::string get_name(){ return name; }
        std::string get_unique_id() { return unique_id; }
        void set_name(std::string input_name) { name = input_name; }
        void set_unique_id(std::string input_unique_id) { unique_id = input_unique_id; }
};