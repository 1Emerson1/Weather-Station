// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "StringServer.h"

#include <string>
#include <array>
#include <regex>
#include <iostream>

using namespace std;

regex intValid("^(((-)?[0-9](\.)?)+)$");
regex dirValid("^([a-zA-Z]{1,9})$");

string winInput;

const int MAX_WSPEED = 120;
const int MIN_WSPEED = 0;
const int SIZE = 32;

array<string, SIZE> winDirList = { "north", "south", "east", "west", "n", "s", "e", "w",
"N", "S", "E", "W", "ne", "nw", "se", "sw", "NE", "NW", "SE", "SW", "North", "South",
"East", "West", "Northeast", "Northwest", "Southwest", "Southeast", "northeast", "northwest", "southwest", "southeast"};

Wind::Wind() {}

void Wind::inputSpeed() {
	cout << returnValue("input") << returnValue("wind_speed") << ": ";
	getline(cin, winInput);

	// if the user does not enter anything, set value to zero
	if (winInput != "") {
		while (true) {
			// check validity & range
			if (!regex_search(winInput, intValid)) {
				invalidInput(returnValue("wind_speed"));
				getline(cin, winInput);
			}
			else {
				if (!checkRange(stoi(winInput), MIN_WSPEED, MAX_WSPEED)) {
					invalidInput(returnValue("wind_speed"));
					getline(cin, winInput);
				}
				windSpeed = stoi(winInput);
				break;
			}
		}
	}
	else {
		windSpeed = 0;
	}
}

void Wind::inputDir() {
	cout << returnValue("input") << returnValue("wind_dir") << ": ";
	getline(cin, winInput);

	if (winInput != "") {
		while (true) {
			if (!regex_search(winInput, dirValid)) {
				invalidInput(returnValue("wind_dir_shrt"));
				getline(cin, winInput);
			}
			// looks for match
			for (int i = 0; i < winDirList.size(); i++) {
				if (winInput == winDirList[i]) {
					break;
				}
				if (i == winDirList.size() - 1) {
					invalidInput(returnValue("wind_dir_shrt"));
					getline(cin, winInput);
					i = -1;
				}
			}
			winDir = winInput;
			break;
		}
	}
	else {
		winDir = returnValue("no_value");
	}
}

int Wind::getSpeed() {
	return windSpeed;
}

string Wind::getDir() {
	return winDir;
}

string Wind::returnValue(string key) {
	return StringServer::returnValue(key);
}