// CREATED BY Emerson Hidalgo

#pragma once // static
#ifndef WEATHERMEASUREMENT_H
#define WEATHERMEASUREMENT_H

struct weather_t {
	temp_t curTemp;
	wind_t wind;
};

weather_t createWeather();

// void print_wind();

#endif // WEATHERMEASUREMENT_H

