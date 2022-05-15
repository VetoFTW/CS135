/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 A
*/

#include <iostream>
using std::string;
using namespace std;

class Profile{
    private:
        string username;
        string displayname;

    public:
        Profile(string usrn, string dspn){
            username = usrn;
            displayname = dspn;
        };
        Profile(){
            username = "";
            displayname = "";
        };

        string getUsername(){return username;};
        string getFullName(){return displayname + " (@" + username + ")";};
        void setDisplayName(string dspn){displayname = dspn;};
};

int main() {
    Profile p1("marco", "Marco");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    p1.setDisplayName("Marco Rossi");
    cout << p1.getUsername() << endl; 
    cout << p1.getFullName() << endl; 

    Profile p2("tarma1", "Tarma Roving");
    cout << p2.getUsername() << endl; 
    cout << p2.getFullName() << endl; 
}
