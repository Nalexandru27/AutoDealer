#include "ClassUtils.h"

void ClassUtils::serializeString(std::ofstream& outF, std::string s)
{
	int stringSize = strlen(s.c_str()) + 1;
	outF.write((char*)&stringSize, sizeof(int));
	outF.write(s.c_str(), sizeof(char) * stringSize);
}

std::string ClassUtils::deserializeString(std::ifstream& inF)
{
	int stringSize;
	inF.read((char*)&stringSize, sizeof(int));
	char buffer[100];
	inF.read(buffer, sizeof(char) * stringSize);
	return std::string(buffer);
}

void ClassUtils::serializeChar(std::ofstream& outF, char* c) {
	int charSize = strlen(c) + 1;
	outF.write((char*)&charSize, sizeof(int));
	outF.write(c, sizeof(char) * charSize);
}

void ClassUtils::deserializeChar(std::ifstream& inF, char*& c)
{
	int charSize;
	inF.read((char*)&charSize, sizeof(int));
	if (c != nullptr) {
		delete[]c;
		c = nullptr;
	}
	char buffer[100];
	inF.read(buffer, sizeof(char) * charSize);
	c = new char[strlen(buffer) + 1];
	strcpy_s(c, strlen(buffer) + 1, buffer);
	c[strlen(buffer)] = '\0';
}

