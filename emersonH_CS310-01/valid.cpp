#include "pch.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

void invalidInput(string inputName) {
	cout << "Invalid input!" << endl;
	cout << "Please enter the " << inputName << ": ";
}

bool empty_variable(string input) {
	if (input.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool checkRange(string compareVal, int MIN_RANGE, int MAX_RANGE) {
	if (MIN_RANGE > stoi(compareVal) || stoi(compareVal) >= MAX_RANGE) {
		return false;
	} else {
		return true;
	}
}