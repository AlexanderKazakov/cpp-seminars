#include <iostream>
#include <fstream>
#include <cassert>
#include <map>

#include "Settings.hpp"

using namespace std;


string trimSpaces(const string& s)
{
	size_t from = s.find_first_not_of(' ');
	size_t to = s.find_last_not_of(' ');
	return s.substr(from, to + 1 - from);
}


pair<string, string> splitLine(const string& line)
{
	size_t position = line.find(':');
	if (position == line.size())
	{
		return {"",""};
	}
	string a = line.substr(0, position);
	string b = line.substr(position + 1);
	return {trimSpaces(a), trimSpaces(b)};
}


map<string, string> parseSettingsToMap(const std::string& filename)
{
	ifstream fileSettings(filename);
	map<string, string> settings;
	for (string line; getline(fileSettings, line);)
	{
		pair<string, string> p = splitLine(line);
		settings[p.first] = p.second;
	}
	return settings;
}


Settings parseSettings(const std::string& filename)
{
	Settings settings;
	map<string, string> settingsMap = parseSettingsToMap(filename);
	/*
	settings.length = settingsMap.at("length");
	settings.clock = settingsMap.at("clock");
	settings.weight = settingsMap.at("weight");
	*/
#define PARAM(name) settings.name = settingsMap.at(#name);
#include "Settings.def"
#undef PARAM
	return settings;
}


int main()
{
	Settings settings = parseSettings("settings.txt");
	std::cout << "length: " << settings.length << std::endl;
	std::cout << "clock : " << settings.clock << std::endl;
	std::cout << "weight: " << settings.weight << std::endl;
	std::cout << "charge: " << settings.charge << std::endl;
}

