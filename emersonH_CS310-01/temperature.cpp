// contains temperature fncs

#include "pch.h"
#include "valid.h"
#include "temperature.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string curTemp;
const int MAX_TEMP = 120;
const int MIN_TEMP = -30;

regex tempValid("^(((-)?[0-9](\.)?)+)$");

string getTemp() {
	// current temperature
	cout << "Please enter the current temperature: ";
	getline(cin, curTemp);
	while (true) {
		// check validity & range
		if (regex_search(curTemp, tempValid)) {
			if (checkRange(curTemp, MIN_TEMP, MAX_TEMP)) {
				break;
			} else {
				invalidInput("current temperature");
				getline(cin, curTemp);
			}
		}
	}
	return curTemp;
}


