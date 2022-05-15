/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 11 B
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
        Network()   {numUsers = 0;};

        bool addUser(string usrn, string dspn){
            if(numUsers < MAX_USERS)
                if(usrn.length() != 0 && isAlphaOrNumOnly(usrn) && findID(usrn) == -1){
                    profiles[numUsers] = Profile(usrn, dspn);
                    numUsers += 1;
                    return true;
                }
            return false;
        };
};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     
  cout << nw.addUser("luigi", "Luigi") << endl;     

  cout << nw.addUser("mario", "Mario2") << endl;    
  cout << nw.addUser("mario 2", "Mario2") << endl;  
  cout << nw.addUser("mario-2", "Mario2") << endl;  

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i),
                 "Mario" + to_string(i)) << endl;   

  cout << nw.addUser("yoshi", "Yoshi") << endl; 
}