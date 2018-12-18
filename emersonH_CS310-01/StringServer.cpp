#include "pch.h"
#include "StringServer.h"
#include "valid.h"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

string filePath = "english.txt";
string lanInput;
regex lanValid("^[0-1]{1}$");

void StringServer::setLanguage() {
	cout << "Please select your prefer language: " << endl;
	cout << " 0 - English\n 1 - Pig Latin" << endl;
	getline(cin, lanInput);

	if (lanInput != "") {
		while (true) {
			if (!regex_search(lanInput, lanValid)) {
				invalidInput(returnValue("language"));
				getline(cin, lanInput);
			}
			else {
				language = stoi(lanInput);
				break;
			}
		}
	}
	else {
		language = 0;
	}
	system("CLS");
}

string StringServer::returnValue(string inputKey) {
	// english default language
	if (language == 1) {
		// changes path to pig latin
		filePath = "piglatin.txt";
	} else {
		// english
		filePath = "english.txt";
	}
	ifstream myFile(filePath);

	if (myFile.is_open()) {
		// search for key
		while (myFile.good()) {
			getline(myFile, key, '\n');
			int start = 0;
			int end = key.find(':');

			// matches keys
			if (key.substr(start, end) == inputKey) {
				// retrieves value
				start = end + 1;
				end = key.find(';');
				value = key.substr(start, end - start);
				break;
			}
		}

	} else {
		cout << "Error opening file." << endl;
	}
	myFile.close();
	return value;
}