// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

// TODO:
// -------
// Fix stringValid regex
// Fix input ranges for temp and wind speed
// Try test cases

#include "pch.h"
#include <string>
#include <iostream>
#include <array>
#include <sstream>
#include <regex>
#include "emersonH_CS310-01.h"

using namespace std;
ostringstream oss;

// weather variables
string weatherStat;
string curTemp;
string windSpeed;
string windDir;
const int MAX_TEMP = 120;
const int MIN_TEMP = -30;
const int MAX_WSPEED = 120;
array<string, 20> winDirList {"north", "south", "east", "west", "N", "S", "E", "W", "NE", "NW", "SE", "SW", "North", "South", "East", "West", "Northeast", "Northwest", "Southwest", "Southeast"};

// menu
string menu = " 1 - Insert weather information.\n 2 - Display current weather.\n 4 - Exit";
string menuInput;

// regex
regex menuValid("[1-4]");
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");
regex dirValid("^([a-zA-Z]{1,9})$");
regex intValid("^(((-)?[0-9](\.)?)+)$");

void invalidInput(string inputName) {
	cout << "Invalid input!" << endl;
	cout << "Please enter the " << inputName << ": ";
}

bool empty_variable(string input) {
	if (input.empty()) {
		return true;
	} else {
		return false;
	}
}

void setWeather() {
	// wind direction
	cout << "Please enter the wind direction (e.g North, South, West, East): ";
	getline(cin, windDir);
	while (true) {
		if (!regex_search(windDir, dirValid)) {
			invalidInput("wind direction");
			getline(cin, windDir);
		}

		int hit = 0;
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
	
	// wind speed
	cout << "Please enter the wind speed: ";
	getline(cin, windSpeed);

	while (true) {
		if (!regex_search(windSpeed, intValid)) {
			invalidInput("wind speed");
			getline(cin, windSpeed);
		}
		if (0 > stoi(windSpeed) || stoi(windSpeed) >= MAX_WSPEED) {
			invalidInput("wind speed");
			getline(cin, windSpeed);
		}
		break;
	}

	// current temperature
	cout << "Please enter the current temperature: ";
	getline(cin, curTemp);
	while (true) {
		if (!regex_search(curTemp, intValid)) {
			invalidInput("current temperature");
			getline(cin, curTemp);
		}
		if (MIN_TEMP > stoi(curTemp) || stoi(curTemp) >= MAX_TEMP) {
			invalidInput("current temperature");
			getline(cin, curTemp);
		}
		break;
	}
	
}

// display current weather
void printWeather() {
	// check for empty strings
	if (empty_variable(windDir)) {
		cout << "No wind direction entered!" << endl;
	}
	if (empty_variable(windSpeed)) {
		cout << "No window speed entered!" << endl;
	}
	if (empty_variable(curTemp)) {
		cout << "No temperature entered!" << endl;
	}
	cout << "The " << weatherStat << " Weather Station" << endl;
	cout << "Temperature: " << curTemp << " F" << endl;
	cout << "Wind: " << windSpeed << " MPH " << windDir << endl;
}

// BEGINNING OF MAIN
int main() {
	// weather station name
	cout << "Please enter the name of your weather station: ";
	getline(cin, weatherStat);
	while (true) {
		if (regex_match(weatherStat, nameValid)) {
			break;
		} else {
			invalidInput("name of your weather station");
			getline(cin, weatherStat);
		}
	} 

	bool running = true;
	// beginning of while loop
	while (running) {
		// menu loop
		cout << "Please select one of the following options: " << endl;
		cout << menu << endl;
		cin >> menuInput;
		cin.ignore();	// clears buffer

		// valid input for menu selection
		if (regex_search(menuInput, menuValid)) {
			switch (stoi(menuInput)) {
			case 1: setWeather();
				break;
			case 2: printWeather();
				break;
			case 3: cout << "Feature not added!" << endl;
				break;
			case 4: running = false;
				cout << "Goodbye!";
				running = false;
				return 0;
				break;
			default: cout << "Invalid input!" << endl;
				break;
			}
		}
		else {
			cout << "What are you doing?" << endl;
		}
	}
	return 0;
}

