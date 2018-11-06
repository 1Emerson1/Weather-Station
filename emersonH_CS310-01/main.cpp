// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "wind.h"
#include "valid.h"
#include "temperature.h"
#include "weatherMeasurement.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>
#include<sstream>

using namespace std;

// regex
regex sizeValid("^[1-9][0-9]*$");
regex menuValid("^[1-4]");
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");

// pointers
weather_t *weatherArr;
long SIZE = 0;

string weatherStat;
int counter = 0;
int histCount = 0;

// array fnc helper
void addElem(weather_t *arr, weather_t elem) {
	// pushes elements back
	for (int i = SIZE - 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	// adds elem to first index
	arr[0] = elem;
}

void setWeather() {
	// resets counter to avoid array out of bound
	if (counter == SIZE) {
		counter = 0;
	}
	// add elements to its specific array
	addElem(weatherArr, createWeather());
	// counter for array
	counter++;
	// counter for num of history added
	histCount++;
}

// display weather history
void printHistory() {
	cout << "The " << weatherStat << " Weather Station" << endl;
	if (histCount == 0) {
		cout << "No history added  yet!" << endl;
	}
	for (int i = 0; i < histCount; i++) {
		cout << "Temperature: " << weatherArr[i].curTemp.curTemp << " F" << endl;
		cout << "Wind: " << weatherArr[i].wind.winSpeed << " MPH " << weatherArr[i].wind.winDir << endl;
	}
} 

// displays current weather station
void printCurrent() {
	cout << "The " << weatherStat << " Weather Station" << endl;
	if (histCount == 0) {
		cout << "No history added  yet!" << endl;
	}
	else {
		cout << "Temperature: " << weatherArr[0].curTemp.curTemp << " F" << endl;
		cout << "Wind: " << weatherArr[0].wind.winSpeed << " MPH " << weatherArr[0].wind.winDir << endl;
	}
}

// BEGINNING OF MAIN
int main() {
	// menu
	string menu = " 1 - Insert weather information\n 2 - Display current weather\n 3 - Display weather history\n 4 - Exit";
	string menuInput;

	bool running = true;

	// ask user for history size
	cout << "Please enter the size of history: ";
	string arrTemp;
	long newSize;
	getline(cin, arrTemp);
	while (true) {
		if (!regex_match(arrTemp, sizeValid)) {
			invalidInput("size of history");
			getline(cin, arrTemp);
		} else {
			stringstream(arrTemp) >> newSize;
			break;
		}
	}

	// creates user defined array 
	weatherArr = new (nothrow) weather_t[newSize];
	SIZE = newSize;

	// weather station name
	cout << "Please enter the name of your weather station: ";
	getline(cin, weatherStat);
	while (true) {
		if (!regex_match(weatherStat, nameValid)) {
			invalidInput("name of your weather station");
			getline(cin, weatherStat);
		}
		else {
			break;
		}
	}

	// beginning of menu while loop
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