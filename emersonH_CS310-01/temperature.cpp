// contains temperature fncs

#include "pch.h"
#include "valid.h"
#include "temperature.h"
#include "emersonH_CS310-01.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

string setTemp(string curTemp, regex intValid, int MIN_TEMP, int MAX_TEMP) {
	// current temperature
	cout << "Please enter the current temperature: ";
	getline(cin, curTemp);
	while (true) {
		// check validity & range
		if (regex_search(curTemp, intValid)) {
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


