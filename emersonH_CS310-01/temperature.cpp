// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "valid.h"
#include "temperature.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string input;
temp_t newTemp;
const int MAX_TEMP = 120;
const int MIN_TEMP = -30;

regex tempValid("^(((-)?[0-9](\.)?)+)$");

temp_t getTemp() {
	// current temperature
	cout << "Please enter the current temperature: ";
	getline(cin, input);

	if (input != "") {
		while (true) {
			// check validity & range
			if (!regex_search(input, tempValid)) {
				invalidInput("current temperature");
				getline(cin, input);
			} else {
				if (!checkRange(stoi(input), MIN_TEMP, MAX_TEMP)) {
					invalidInput("current temperature");
					getline(cin, input);	
				}
				newTemp.curTemp = stoi(input);
				break;
			}
		}
	} else {
		newTemp.curTemp = 0;
	}
	return newTemp;
}

