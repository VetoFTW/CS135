/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Project 2 A B C D E
*/

#include <iostream>
#include <fstream>
#include <vector>
using std::string;
using std::vector;

/*
    Helper Function that takes in a string, and returns
    a vector of strings which were seperated between a space
*/
vector<string> splitStringIntoList(string s){
    vector<string> list;
    string sAssembler = "";

    for (int i = 0; i < s.length(); i++){
        if (s[i] != ' '){
            sAssembler += s[i];
        } else{
            list.push_back(sAssembler);
            sAssembler = "";
        }
    }
    list.push_back(sAssembler);
    return list;
}

/*
    Helper Function that takes in a line and splits it into
    two strings: word and pronunciation.
*/
void splitStringOnSpace(string s, string &before, string &after){
    before = "";
    after = "";

    int i = 0;
    while (i < s.length() && not isspace(s[i])){
        before += s[i];
        i++;
    }

    i += 2;
    while (i < s.length()){
        after += s[i];
        i++;
    }
}

/*
    Helper Function that takes in a word and checks its validity.
    Can only be alphabetic with an exemptions on the apostrophe
*/
bool isValidWord(string w){
    for (int i = 0; i < w.length(); i++)
        if (not isalpha(w[i]))
            if (w[i] != '\'')
                return false;
    return true;
}

/*
    Function that opens the Dictionary file
*/
std::fstream openDictionary(){
    std::fstream file("cmudict.0.7a");
    if (file.fail()){
        std::cerr << "Could Not Open File" << std::endl;
        exit(1);
    }
    return file;
}

/*
    Searches Disctionary for input words pronunciation
*/
string getPronunciation(string w){
    std::fstream file = openDictionary();
    string line, word, pronunciation;

    while (getline(file, line)){
        splitStringOnSpace(line, word, pronunciation);
        if (isValidWord(word))
            if (word == w) return pronunciation;
    }
    return "Not Found";
}

/*
    Searches Disctionary for words with the same pronnunciation
*/
vector<string> getIdentical(string w, string p){
    vector<string> list;
    string line, word, pronunciation;
    std::fstream file = openDictionary();

    while (getline(file, line)){
        splitStringOnSpace(line, word, pronunciation);
        if (isValidWord(word) && p == pronunciation && w != word) list.push_back(word);
    }
    return list;
}

/*
    Searches Disctionary for words with the same phenom sequence,
    with one fault
*/
vector<string> getSimilarViaReplace(string w, string p){
    vector<string> list, plist, pronunciationList;
    string line, word, pronunciation;
    std::fstream file = openDictionary();

    while (getline(file, line)){
        splitStringOnSpace(line, word, pronunciation);

        if (isValidWord(word) && w != word){
            plist = splitStringIntoList(p);
            pronunciationList = splitStringIntoList(pronunciation);
            if (plist.size() == pronunciationList.size()){
                int differenceTracker = 0;
                for (int i = 0; i < plist.size(); i++){
                    if (plist[i] != pronunciationList[i])
                        differenceTracker++;
                }
                if (differenceTracker == 1)
                    list.push_back(word);
            }
        }
    }
    return list;
}

/*
    Searches Disctionary for words with the same phenom sequence,
    with one additional phenom
*/
vector<string> getSimilarViaAdd(string w, string p){
    vector<string> list, plist, pronunciationList;
    string line, word, pronunciation;
    std::fstream file = openDictionary();

    while (getline(file, line)){
        splitStringOnSpace(line, word, pronunciation);
        if (isValidWord(word) && w != word){
            plist = splitStringIntoList(p);
            pronunciationList = splitStringIntoList(pronunciation);
            if (plist.size() + 1 == pronunciationList.size()){
                int sequenceTracker = 0;
                int auxIndex = 0;
                for (int i = 0; i < plist.size(); i++){
                    if (plist[i] == pronunciationList[auxIndex])
                        sequenceTracker++;
                    else if (plist[i] == pronunciationList[auxIndex + 1]){
                        sequenceTracker++;
                        auxIndex++;
                    }
                    auxIndex++;
                }
                if (sequenceTracker == plist.size())
                    list.push_back(word);
            }
        }
    }
    return list;
}

/*
    Searches Disctionary for words with the same phenom sequence,
    with one missing phenom
*/
vector<string> getSimilarViaSubtract(string w, string p){
    vector<string> list, plist, pronunciationList;
    string line, word, pronunciation;
    std::fstream file = openDictionary();

    while (getline(file, line)){
        splitStringOnSpace(line, word, pronunciation);
        if (isValidWord(word) && w != word){
            plist = splitStringIntoList(p);
            pronunciationList = splitStringIntoList(pronunciation);
            if (plist.size() - 1 == pronunciationList.size()){
                int sequenceTracker = 0;
                int auxIndex = 0;
                for (int i = 0; i < plist.size(); i++){
                    if (plist[i] == pronunciationList[auxIndex])
                        sequenceTracker++;
                    else
                        auxIndex--;
                    auxIndex++;
                }
                if (sequenceTracker == pronunciationList.size())
                    list.push_back(word);
            }
        }
    }
    return list;
}

/*
    Main Function
*/
int main(){

    string word, pronunciation;
    vector<string> identicalWords, similarViaReplace, similarViaAdd, similarViaSubtract;

    std::cin >> word;

    for (int i = 0; i < word.length(); i++)
        word[i] = toupper(word[i]);

    pronunciation = getPronunciation(word);
    identicalWords = getIdentical(word, pronunciation);
    similarViaReplace = getSimilarViaReplace(word, pronunciation);
    similarViaAdd = getSimilarViaAdd(word, pronunciation);
    similarViaSubtract = getSimilarViaSubtract(word, pronunciation);

    if (pronunciation == "Not Found")
        std::cout << pronunciation << std::endl;
    else{
        std::cout << "Pronunciation \t: " << pronunciation << '\n'
                  << std::endl;

        std::cout << "Identical \t:";
        for (int i = 0; i < identicalWords.size(); i++)
            std::cout << " " << identicalWords[i];
        std::cout << '\n';

        std::cout << "Replace phoneme\t:";
        for (int i = 0; i < similarViaReplace.size(); i++)
            std::cout << " " << similarViaReplace[i];
        std::cout << '\n';

        std::cout << "Add phoneme \t:";
        for (int i = 0; i < similarViaAdd.size(); i++)
            std::cout << " " << similarViaAdd[i];
        std::cout << '\n';

        std::cout << "Remove phoneme \t:";
        for (int i = 0; i < similarViaSubtract.size(); i++)
            std::cout << " " << similarViaSubtract[i];
        std::cout << '\n';
    }
    return 0;
}