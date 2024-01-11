#pragma once
#include <string>
class Person
{
protected:
	std::string name = "";
	int age = 0;
	bool isMarried = false;
public:
	Person(std::string name, int age, bool isMarried);
	std::string getName();
	int getAge();
	bool getIsMarried();
	void setMarried();
	void setNotMarried();
	virtual void displayInfo();
};

