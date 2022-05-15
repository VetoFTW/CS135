/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 C
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

class Network{
    private:
        static const int MAX_USERS = 20;
        int numUsers;
        Profile profiles[MAX_USERS];
        bool following[MAX_USERS][MAX_USERS];

        int findID(string usrn){
            for(int i = 0; i <= numUsers; i++)
                if(profiles[i].getUsername() == usrn)
                    return i;
            return -1;
        };

        bool isAlphaOrNumOnly(string w){
            for(int i = 0; i < w.length(); i++)
                if(not isalnum(w[i]))
                    return false;
            return true;
        };
    
    public:
        Network(){
            numUsers = 0;
            for(int i = 0; i < MAX_USERS; i++)
                for(int j = 0; j < MAX_USERS; j++)
                    following[i][j] = false;
            };

        bool addUser(string usrn, string dspn){
            if(numUsers < MAX_USERS)
                if(usrn.length() != 0 && isAlphaOrNumOnly(usrn) && findID(usrn) == -1){
                    profiles[numUsers] = Profile(usrn, dspn);
                    numUsers += 1;
                    return true;
                }
            return false;
        };

        bool follow(string usrn1, string usrn2){
            int usrn1ID = findID(usrn1),
                usrn2ID = findID(usrn2);

            if(usrn1ID != -1 && usrn2ID != -1){
                following[usrn1ID][usrn2ID] = true;
                return true;
            }
            return false;
        };

        void printDot(){
            std::cout << "digraph {" << std::endl;
            for(int i = 0; i < numUsers; i++)
                std::cout << "\t\"@" + profiles[i].getUsername() + "\"" << std::endl;
        
            std::cout << "\n";

            for(int i = 0; i < numUsers; i++)
                for(int j = 0; j < numUsers; j++)
                    if(following[i][j] == true)
                        std::cout << "\t\"@" + profiles[i].getUsername() + "\" -> \"@" + profiles[j].getUsername() + "\"" << std::endl;
            std::cout << "}";
        }

};

int main() {
    Network nw;
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    nw.addUser("wario", "Wario");
    
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    nw.follow("mario2", "luigi");

    nw.printDot();
}