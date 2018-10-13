//contains temperature variable declartions of fncs

#ifndef WIND_H
#define WIND_H

#include <string>
#include <regex>
#include <array>

std::string setWSpeed(std::string windSpeed, std::regex intValid, int MIN_WSPEED, int MAX_WSPEED);
std::string setWDir(std::string windDir, std::regex dirValid, std::array<std::string, 32> winDirList);

#endif
