// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>
#include <regex>
#include "emersonH_CS310-01.h"

using namespace std;
ostringstream oss;

/* bool valid_input(string input, string validation) {
	const char* test = input.c_str();
	regex re(validation);
	cmatch match;
	if (regex_match(test, match, re)) {
		return true;
	} else {
		return  false;
	}
}

*/

bool empty_variable(string input) {
	if (input.empty()) {
		return true;
	} else {
		return false;
	}
}

int main() {
	string weatherStat;
	string curTemp;
	string windSpeed;
	string windDir;

	// menu
	string menu = " 1 - Insert weather information.\n 2 - Display current weather.\n 4 - Exit";
	string menuInput;

	// regex
	regex menuValid("[1-4]");
	regex stringValid("[a-zA-Z]");
	regex tempValid("[0-9]+");
	regex intValid("\S^[0-9]+");

	// weather station name
	cout << "Please enter the name of your weather station: ";
	getline(cin, weatherStat);

	bool running = true;
	while (running) {
		cout << "Please select one of the following options: " << endl;
		cout << menu << endl;
		cin >> menuInput;
		cin.ignore();

		// valid input for menu select
		if (regex_search(menuInput, menuValid)) {
			switch (stoi(menuInput)) {
				// wind direction
			case 1: cout << "Please enter the wind direction (e.g North, South, West, East): ";
				getline(cin, windDir);
				while (!regex_search(windDir, stringValid)) {
					cout << "Invalid input!" << endl;
					cout << "Please enter the wind direction: ";
					getline(cin, windDir);
				}
				// wind speed
				cout << "Please enter the wind speed: ";
				getline(cin, windSpeed);
				while (regex_search(windSpeed, intValid)) {
					if (stoi(windSpeed) < 0) {
						cout << "Invalid input!" << endl;
						cout << "Please enter the wind speed: ";
						getline(cin, windSpeed);
					}	
				}

				// current temperature
				cout << "Please enter the current temperature: ";
				getline(cin, curTemp);
				while (!regex_search(curTemp, tempValid)) {
					cout << "Invalid input!" << endl;
					cout << "Please enter the current temperature: ";
					getline(cin, curTemp);
				}
				break;

				// display current weather
			case 2: if (empty_variable(windDir)) {		// check for empty strings
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
				cout << "Wind: " << windSpeed << " mph " << windDir << endl;
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

