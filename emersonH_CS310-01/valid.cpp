// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "StringServer.h"
#include "valid.h"

#include <string>
#include <regex>
#include <iostream>

using namespace std;

StringServer ss_;

void invalidInput(string inputName) {
	cout << ss_.returnValue("invalid_input") << "!" << endl;
	cout << ss_.returnValue("input") << inputName << ": ";
}

bool empty_variable(string input) {
	if (input.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool checkRange(int compareVal, int MIN_RANGE, int MAX_RANGE) {
	if (MIN_RANGE > compareVal || compareVal >= MAX_RANGE) {
		return false;
	} else {
		return true;
	}
}