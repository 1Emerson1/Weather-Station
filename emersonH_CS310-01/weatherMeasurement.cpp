// CREATED BY Emerson Hidalgo

#include "pch.h"
#include "temperature.h"
#include "wind.h"
#include "weatherMeasurement.h"

#include <string>

weather_t createWeather() {
	weather_t newWeather;

	newWeather.curTemp = getTemp();
	newWeather.wind = getWind();

	return newWeather;
}