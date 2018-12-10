#pragma once

/*
struct Settings
{
	std::string length;
	std::string clock;
	std::string weight;
};
*/

#define PARAM(name) std::string name;

struct Settings
{
#include "Settings.def"
};

#undef PARAM


