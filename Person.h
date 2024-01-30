#pragma once
#include <fstream>
class Person
{
protected:
	std::string name = "";
	int age = 0;
	bool isMarried = false;
public:
	Person();
	Person(std::string name, int age, bool isMarried);
	std::string getName();
	void setName(std::string name);
	void setAge(int age);
	int getAge();
	bool getIsMarried();
	void setMarried();
	void setNotMarried();
	virtual void displayInfo();
	void writePersonToTextFile(std::ofstream& file); 
	void writePersonToBinaryFile(std::ofstream& file) const;
	void readPersonFromBinaryFile(std::ifstream& file);
};

