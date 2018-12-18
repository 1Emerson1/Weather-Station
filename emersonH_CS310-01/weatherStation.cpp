// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "temperature.h"
#include "weatherMeasurement.h"
#include "weatherStation.h"
#include "StringServer.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// regex
regex sizeValid("^[1-9][0-9]*$");
regex menuValid("^[1-5]$");
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");

// pointers
Weather *weatherArr;
Weather newReading;
long SIZE = 0;

string menuInput;
string weatherStat;
int counter = 0;
int histCount = 0;

// array fnc helper
void weatherStation::addElem(Weather *arr, Weather elem) {
	// counter for array
	counter++;
	// counter for history
	histCount++;

	if (histCount == 0) {
		arr[0] = elem;
	}
	else {
		// pushes elements back
		for (int i = SIZE - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		// adds elem to first index
		arr[0] = elem;
	}
}

void addElem(weatherStation *arr, weatherStation elem) {
	// counter for array
	counter++;
	// counter for history
	histCount++;

	if (histCount == 0) {
		arr[0] = elem;
	}
	else {
		// pushes elements back
		for (int i = SIZE - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		// adds elem to first index
		arr[0] = elem;
	}
}

void weatherStation::setWeather() {
	// resets counter to avoid array out of bound
	if (counter == SIZE) {
		counter = 0;
	}

	if (histCount > counter) {
		histCount--;
	}

	// add user input to weather
	newReading.allocate();
	// add elements to its specific array
	addElem(weatherArr, newReading);
}

// display weather history
void weatherStation::printHistory(int count) {
	cout << ss.returnValue("the") << weatherStat << ss.returnValue("station") << endl;
	if (histCount == 0) {
		cout << ss.returnValue("no_history") << "!" << endl;
	}
	else {
		for (int i = 0; i < count; i++) {
			cout << ss.returnValue("temp") << ": " << weatherArr[i].getTemp() << ss.returnValue("temp_unit") << endl;
			cout << ss.returnValue("wind") << ": " << weatherArr[i].getWSpeed() << ss.returnValue("speed_unit") << weatherArr[i].getWDir() << endl;
		}
	}
}

void weatherStation::setHistory() {
	cout << ss.returnValue("input") << ss.returnValue("history_size") << ": ";
	string arrTemp;
	getline(cin, arrTemp);
	while (true) {
		if (!regex_match(arrTemp, sizeValid)) {
			invalidInput(ss.returnValue("history_size"));
			getline(cin, arrTemp);
		}
		else {
			stringstream(arrTemp) >> SIZE;
			break;
		}
	}
	system("CLS");
}

void weatherStation::setStationName() {
	cout << ss.returnValue("input") << ss.returnValue("station_name") << ": ";
	getline(cin, weatherStat);
	while (true) {
		if (!regex_match(weatherStat, nameValid)) {
			invalidInput(ss.returnValue("station_name"));
			getline(cin, weatherStat);
		} else {
			break;
		}
	}
	system("CLS");
}

weatherStation weatherStation::createWS() {
	// create weather station
	weatherStation *ws;

	// ask user for history size
	setHistory();

	// creates user defined array 
	weatherArr = new (nothrow) Weather[SIZE];

	// weather station name
	setStationName();

	// beginning of menu while loop
	while (true) {
		cout << ss.returnValue("menu_select") << ": \n" <<
			ss.returnValue("menu_1") + "\n"
			+ ss.returnValue("menu_2") + "\n"
			+ ss.returnValue("menu_3") + "\n"
			+ ss.returnValue("menu_4") + "\n"
			+ ss.returnValue("menu_5") << endl;

		getline(cin, menuInput);

		system("CLS");

		// valid input for menu selection
		if (regex_search(menuInput, menuValid)) {
			switch (stoi(menuInput)) {
			case 1: setWeather();
				break;
			case 2: printHistory(1);
				break;
			case 3: printHistory(histCount);
				break;
			case 4: ss.setLanguage();
				break;
			case 5: cout << ss.returnValue("outro") << "!";
				break;
			default: cout << ss.returnValue("invalid_input") << "!" << endl;
				break;
			}
		}
		else {
			cout << ss.returnValue("invalid_menu") << "?" << endl;
		}
	}
}

