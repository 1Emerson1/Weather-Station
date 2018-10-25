// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include "main.h"
#include "wind.h"
#include "valid.h"
#include "weather.h"
#include "temperature.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

int index;
int num = 0;
const int HIST_SIZE = 4;

// array & its pointer
string wName [HIST_SIZE];
string *nameArr = wName;
string cTemp [HIST_SIZE];
string *tempArr = cTemp;
string wSpeed [HIST_SIZE];
string *speedArr = wSpeed;
string wDir [HIST_SIZE];
string *dirArr = wDir;

// menu
string menu = " 1 - Insert weather information\n 2 - Display current weather\n 3 - Display weather history\n 4 - Exit";
string menuInput;
// regex
regex menuValid("^[1-4]");


// array fnc helper
void addElem(string *arr, string elem) {
	// find next empty index
	for (int i = 0; i < HIST_SIZE; i++) {
		if (arr[i] == "") {
			// add elem
			arr[i] = elem;
			num = i;
			break;
		}
	}
	// check if array is full
	if (num+1 == HIST_SIZE) {
		menu = menu = " 2 - Display current weather\n 3 - Display weather history\n 4 - Exit";
	}

}

void setWeather() {
	// weather station name
	addElem(nameArr, getName());
	// wind direction
	addElem(dirArr, getWDir());
	// wind speed
	addElem(speedArr, getWSpeed());
	// current temperature
	addElem(tempArr, getTemp());
	num++;
}

// display weather history
void printHistory() {
	int prev = num-1;
	for (int i = 0; i < num; i++) {
		// check for empty strings
		if (empty_variable(nameArr[prev])) {
			cout << "No name entered!" << endl;
		}
		cout << "The " << nameArr[prev] << " Weather Station" << endl;
		
		if (empty_variable(tempArr[prev])) {
			cout << "No temperature entered!" << endl;
		}
		cout << "Temperature: " << tempArr[num] << " F" << endl;

		if (empty_variable(speedArr[prev])) {
			cout << "No wind speed entered!" << endl;
		}
		if (empty_variable(dirArr[prev])) {
			cout << "No wind direction entered!" << endl;
		}
		cout << "Wind: " << speedArr[prev] << " MPH " << dirArr[prev] << endl;
		prev--;
	}
}

// displays current weather station
void printCurrent() {
	int prev = num-1;
	// check for empty strings
	if (empty_variable(nameArr[prev])) {
		cout << "No name entered!" << endl;
	}
	cout << "The " << nameArr[prev] << " Weather Station" << endl;

	if (empty_variable(tempArr[prev])) {
		cout << "No temperature entered!" << endl;
	}
	cout << "Temperature: " << tempArr[prev] << " F" << endl;

	if (empty_variable(speedArr[prev])) {
		cout << "No wind speed entered!" << endl;
	}
	if (empty_variable(dirArr[prev])) {
		cout << "No wind direction entered!" << endl;
	}
	cout << "Wind: " << speedArr[prev] << " MPH " << dirArr[prev] << endl;
}

// BEGINNING OF MAIN
int main() {
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
			case 2: printCurrent();
				break;
			case 3: printHistory();
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