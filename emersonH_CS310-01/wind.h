// CREATED BY Emerson Hidalgo
#pragma once
#ifndef WIND_H
#define WIND_H

#include <string>

class Wind {
		int windSpeed;
		std::string winDir;
	public:
		Wind();
		void inputDir();
		void inputSpeed();
		int getSpeed();
		std::string getDir();
};

#endif
