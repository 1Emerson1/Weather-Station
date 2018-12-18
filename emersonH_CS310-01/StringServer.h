// CREATED BY Emerson Hidalgo
#pragma once
#ifndef STRINGSERVER_H
#define STRINGSERVER_H

#include "valid.h"
#include <string>

class StringServer {
	int language = 0;
	std::string key;
	std::string value;
	public:
		void setLanguage();
		std::string returnValue(std::string key);
};

#endif