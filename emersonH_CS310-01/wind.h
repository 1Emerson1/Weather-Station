// CREATED BY Emerson Hidalgo
#pragma once
#ifndef WIND_H
#define WIND_H

#include "StringServer.h"
#include "valid.h"
#include <string>

class Wind: public StringServer {
		int windSpeed;
		std::string winDir;
	public:
		Wind();
		void inputDir();
		void inputSpeed();
		int getSpeed();
		std::string getDir();
		std::string returnValue(std::string key);
};

#endif
