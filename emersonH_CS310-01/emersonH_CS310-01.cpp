// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;
ostringstream oss;

int main() {
	string weatherStat = "Mars";
	int curTemp = 75;
	int windSpeed = 5;
	string windDir = "North";

	// request name of weather station
	cout << "Please enter the name of your weather station: ";
	getline(cin, weatherStat);

	// wind direction
	cout << "Please enter the wind direction: ";
	getline(cin, windDir);

	// temperature
	cout << "Please enter the current temperature: ";
	cin >> curTemp;

	// wind speed
	cout << "Please enter the wind speed: ";
	cin >> windSpeed;

	// cout << "Hello World!" << endl;
	cout << "The " << weatherStat << " Weather Station" << endl;
	cout << "Temperature: " << curTemp << " F" << endl;
	cout << "Wind: " << windSpeed << " mph " << windDir << endl;

	return 0;
}

