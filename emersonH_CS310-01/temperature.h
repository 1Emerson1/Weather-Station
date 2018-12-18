// CREATED BY Emerson Hidalgo
#pragma once
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "StringServer.h"
#include "valid.h"
#include <string>

class Temperature: public StringServer {
	int curTemp;
	public:
		Temperature();
		void setTemp();
		int getTemp();
		std::string returnValue(std::string key);
};
#endif
