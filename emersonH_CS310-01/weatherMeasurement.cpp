// CREATED BY Emerson Hidalgo
#include "pch.h"
#include "wind.h"
#include "temperature.h"
#include "weatherMeasurement.h"

Weather::Weather() {}

void Weather::allocate() {
	temp.setTemp();
	w.inputSpeed();
	w.inputDir();
}

std::string Weather::getWDir() {
	return w.getDir();
}

int Weather::getWSpeed() {
	return w.getSpeed();
}

int Weather::getTemp() {
	return temp.getTemp();
}


