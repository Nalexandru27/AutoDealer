#pragma once
#include <string>
#include <fstream>
class ClassUtils
{
public:
	static void serializeString(std::ofstream& outF, std::string s);
	static std::string deserializeString(std::ifstream& inF);
	static void serializeChar(std::ofstream& outF, char* c);
	static void deserializeChar(std::ifstream& inF, char* & c);
};

