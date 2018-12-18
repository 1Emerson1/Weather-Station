// CREATED BY Emerson Hidalgo
#pragma once
#ifndef WEATHERSTATION_H
#define WEATHERSTATION_H

#include "weatherMeasurement.h"
#include "StringServer.h"
#include <string>

class weatherStation {
	int counter = 0;
	int histCount = 0;
	std::string weatherStat;
	StringServer ss;

	public:
		void addElem(Weather *arr, Weather elem);
		void setWeather();
		void printHistory(int count);
		void setHistory();
		void setStationName();
		weatherStation createWS();
};
#endif // !WEATHERSTATION_H

