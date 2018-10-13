//contains temperature variable declartions of fncs

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <string>
#include <regex>

std::string setTemp(std::string curTemp, std::regex intValid, int MIN_TEMP, int MAX_TEMP);

#endif
