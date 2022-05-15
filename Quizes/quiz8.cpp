/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Quiz 8
*/

#include <iostream>
using namespace std;

void remove_e(string &sentence) {
	string temp;
	int offset = 0;
	for (int i = 0; i < sentence.length(); ++i) {
		if (sentence[i] == 'e') {
			++offset;
		} else {
			string str(1, sentence[i]);
			temp.append(str);
		}
	}
	sentence = temp;
}