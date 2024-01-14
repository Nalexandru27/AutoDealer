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
	Employee();
	Employee(std::string name, int age, bool isMarried, float salary, const char* department, const char* job, std::string jobDescription, bool isManager, int noPreviousWorkingExperience, std::string* experience, int noLanguagesKnown, std::string* languagesKnown, float bonus);
	Employee(const Employee& e);
	Employee& operator=(const Employee& e);
	~Employee();
	void setSalary(float salary);
	void setDepartment(const char* department);
	void setJob(const char* job);
	void setJobDescription(std::string jobDescription);
	void setIsManager();
	void setIsNotManager();
	void setExperience(int value, std::string* experience);
	void setLanguagesKnown(int value, std::string* languagesKnown);
	void setBonus(float bonus);
	void addJobDescription(std::string description);
	void addExperience(std::string experience);
	void displayInfo();
	friend std::istream& operator>>(std::istream& in, Employee& e);
};

