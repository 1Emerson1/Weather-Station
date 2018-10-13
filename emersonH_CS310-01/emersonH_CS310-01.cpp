// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "temperature.h"
#include "emersonH_CS310-01.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

// weather variables
string curTemp;
string windDir;
string windSpeed;
string weatherStat;
const int MAX_TEMP = 120;
const int MIN_TEMP = -30;
const int MAX_WSPEED = 120;
const int MIN_WPSEED = 0;
const int ARR_SIZE = 32;
array<string, ARR_SIZE> winDirList = {"north", "south", "east", "west", "n", "s", "e", "w",
"N", "S", "E", "W", "ne", "nw", "se", "sw", "NE", "NW", "SE", "SW", "North", "South", 
"East", "West", "Northeast", "Northwest", "Southwest", "Southeast", "northeast", "northwest", "southwest", "southeast" };

// menu
string menu = " 1 - Insert weather information.\n 2 - Display current weather.\n 4 - Exit";
string menuInput;

// regex
regex menuValid("[1-4]");
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");
regex dirValid("^([a-zA-Z]{1,9})$");
regex dirMatch("\b(?:north|south)(?:\h*(?:east|west))?\b|\b(?:east|west|[NS][WE]?|[EW])\b");
regex intValid("^(((-)?[0-9](\.)?)+)$");

void setWeather() {
	// wind direction
	windDir = setWDir(windDir, dirValid, winDirList);
	// wind speed
	windSpeed = setWSpeed(windSpeed, intValid, MIN_WPSEED, MAX_WSPEED);
	// current temperature
	curTemp = setTemp(curTemp, intValid, MIN_TEMP, MAX_TEMP);
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