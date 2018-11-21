// CREATED BY Emerson Hidalgo
#pragma once

#ifndef WEATHERMEASUREMENT_H
#define WEATHERMEASUREMENT_H

class Weather {
		Temperature temp;
		Wind w;
	public:
		Weather();
		void allocate();
		int getTemp();
		std::string getWDir();
		int getWSpeed();
};

#endif // WEATHERMEASUREMENT_H

