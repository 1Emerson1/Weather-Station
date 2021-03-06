// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "weatherStation.h"
#include "StringServer.h"

#include <array>
#include <regex>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

StringServer m_ss;
string menuIn;
string station;
weatherStation *stationArr;

regex menu("^[1-5]$");
regex station_regex("^[a-zA-Z]$");

void selectWS() {
	cout << m_ss.returnValue("select_station") << endl;
	getline(cin, station);

	while (true) {
		if (!regex_match(station, station_regex)) {

		}
	}
}

// BEGINNING OF MAIN
int main() {
	// ask user for language
	m_ss.setLanguage();

	// create a new weather station

	while (true) {
		cout << m_ss.returnValue("menu_select") << ": \n" << endl;
		getline(cin, menuIn);

		system("CLS");

		if (regex_search(menuIn, menu)) {
			
			switch (stoi(menuIn)) {
				case 1: addElem(stationArr, createWS());
					break;
				// select weather station
				case 2: selectWS();
					break;
				// print all weather readings for all stations
				case 3: 
					break;
				// change language
				case 4: m_ss.setLanguage();
					break;
				// exit
				case 5: cout << m_ss.returnValue("outro") << endl;
					return 0;
					break;
			}
		} else {
			cout << m_ss.returnValue("invalid_menu") << "?" << endl;
		}
	}

}