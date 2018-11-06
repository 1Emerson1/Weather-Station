// CREATED BY Emerson Hidalgo

#pragma once
#ifndef WIND_H
#define WIND_H

#include <string>

struct wind_t {
	int winSpeed;
	std::string winDir;
};

wind_t getWind();

#endif
