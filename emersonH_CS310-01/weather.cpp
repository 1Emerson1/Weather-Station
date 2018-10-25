#include "pch.h"
#include "valid.h"
#include "main.h"
#include "weather.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

string weatherStat;
regex nameValid("^([a-zA-Z0-9 ]{1,50})$");

string getName() {
	// weather station name
	cout << "Please enter the name of your weather station: ";
	getline(cin, weatherStat);
	while (true) {
		if (regex_match(weatherStat, nameValid)) {
			break;
		}
		else {
			invalidInput("name of your weather station");
			getline(cin, weatherStat);
		}
	}
	return weatherStat;
}