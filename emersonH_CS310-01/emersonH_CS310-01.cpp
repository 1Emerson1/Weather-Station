// emersonH_CS310-01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	string weatherStat = "Mars";
	int curTemp = 75;
	int windSpeed = 5;
	string windDir = "North";

	// cout << "Hello World!" << endl;
	cout << "The " << weatherStat << " Weather Station" << endl;
	cout << "Temperature: " << curTemp << " F" << endl;
	cout << "Wind: " << windSpeed << " mph " << windDir << endl;

	return 0;
}

