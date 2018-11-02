// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "main.h"
#include "wind.h"
#include "valid.h"
#include "temperature.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>

using namespace std;

// regex
regex sizeValid("^[1-9][0-9]*$");
regex menuValid("^[1-4]");
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");

// pointers
int *speedArr;
int *tempArr;
string *dirArr;
long long SIZE = 0;

string weatherStat;
int counter = 0;
int histCount = 0;

// array fnc helper
void addElem(int *arr, int elem) {
	// pushes elements back
	for (int i = SIZE - 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	// adds elem to first index
	arr[0] = elem;
}

// same fnc as above but for string variables
void addElem(string *arr, string elem) {
	for (int i = SIZE - 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = elem;
}

void setWeather() {
	// resets counter to avoid array out of bound
	if (counter == SIZE) {
		counter = 0;
	}
	// add elements to its specific array
	addElem(dirArr, getWDir());
	addElem(speedArr, getWSpeed());
	addElem(tempArr, getTemp());
	
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
		cout << "Temperature: " << tempArr[i] << " F" << endl;
		cout << "Wind: " << speedArr[i] << " MPH " << dirArr[i] << endl;
	}
}

// displays current weather station
void printCurrent() {
	cout << "The " << weatherStat << " Weather Station" << endl;
	if (histCount == 0) {
		cout << "No history added  yet!" << endl;
	}
	else {
		cout << "Temperature: " << tempArr[0] << " F" << endl;
		cout << "Wind: " << speedArr[0] << " MPH " << dirArr[0] << endl;
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
	long long newSize;
	getline(cin, arrTemp);
	while (true) {
		if (!regex_match(arrTemp, sizeValid)) {
			invalidInput("size of history");
			getline(cin, arrTemp);
		} else {
			newSize = stoll(arrTemp);
			break;
		}
	}

	// array
	tempArr = new (nothrow) int[newSize];
	speedArr = new (nothrow) int[newSize];
	dirArr = new (nothrow) string[newSize];
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