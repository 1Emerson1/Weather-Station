// contains wind fncs
#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "emersonH_CS310-01.h"

#include <string>
#include <array>
#include <regex>
#include <iostream>

using namespace std;

string setWSpeed(string windSpeed, regex intValid, int MIN_WSPEED, int MAX_WSPEED) {
	cout << "Please enter the wind speed: ";
	getline(cin, windSpeed);

	while (true) {
		// check validity & range
		if (regex_search(windSpeed, intValid)) {
			if (checkRange(windSpeed, MIN_WSPEED, MAX_WSPEED)) {
				break;
			} else {
				invalidInput("wind speed");
				getline(cin, windSpeed);
			}
		} 
	}
	return windSpeed;
}

string setWDir(string windDir, regex dirValid, array<string, 32> winDirList) {
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