// contains wind fncs
#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "main.h"

#include <string>
#include <array>
#include <regex>
#include <iostream>

using namespace std;

regex intValid("^(((-)?[0-9](\.)?)+)$");
regex dirValid("^([a-zA-Z]{1,9})$");

string windSpeed;
string windDir;
const int MAX_WSPEED = 120;
const int MIN_WSPEED = 0;
const int ARR_SIZE = 32;
array<string, ARR_SIZE> winDirList = { "north", "south", "east", "west", "n", "s", "e", "w",
"N", "S", "E", "W", "ne", "nw", "se", "sw", "NE", "NW", "SE", "SW", "North", "South",
"East", "West", "Northeast", "Northwest", "Southwest", "Southeast", "northeast", "northwest", "southwest", "southeast"};

string getWSpeed() {
	cout << "Please enter the wind speed: ";
	getline(cin, windSpeed);

	while (true) {
		// check validity & range
		if (!regex_search(windSpeed, intValid)) {
			invalidInput("wind speed");
			getline(cin, windSpeed);
		} else {
			if (checkRange(windSpeed, MIN_WSPEED, MAX_WSPEED)) {
				break;
			}
			else {
				invalidInput("wind speed");
				getline(cin, windSpeed);
			}
		}
	}
	return windSpeed;
}

string getWDir() {
	cout << "Please enter the wind direction (e.g North, South, West, East): ";
	getline(cin, windDir);

	while (true) {
		if (!regex_search(windDir, dirValid)) {
			invalidInput("wind direction");
			getline(cin, windDir);
		}
		int hit = 0;
		// looks for match
		for (int i = 0; i < winDirList.size(); i++) {
			if (windDir == winDirList[i]) {
				hit = 1;
				break;
			}
			if (i == winDirList.size()-1) {
				invalidInput("wind direction");
				getline(cin, windDir);
				i = -1;
			}
		}
		break;
	}
	return windDir;
}