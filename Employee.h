#pragma once
#include "Person.h"
#include <string>

class Employee:public Person
{
	float salary = 0.0f;
	char* department = nullptr;
	char* job = nullptr;
	std::string jobDescription = "";
	bool isManager = false;
	int noPreviousWorkingExperience = 0;
	std::string* experience = nullptr;
	int noLanguagesKnown = 0;
	std::string* languagesKnown = nullptr;
	float bonus = 0.0f;
public:
	void addJobDescription(std::string description);
	void modifySalary(float newSalary);
	void addBonus(float bonus);
	void promoteToManager();
	void noLongerManager();
	void addExperience(std::string experience);
};

