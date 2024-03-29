#pragma once
#include "Person.h"
#include <string>
#include "ClassUtils.h"
#include <vector>
class Employee:public Person
{
private:

	float salary = 0.0f;
	char* department = nullptr;
	char* job = nullptr;
	std::string jobDescription = " ";
	bool isManager = false;
	int noPreviousWorkingExperience = 0;
	std::string* experience = nullptr;
	int noLanguagesKnown = 0;
	std::string* languagesKnown = nullptr;
	float bonus = 0.0f;

public:
	//constructors
	Employee();
	Employee(std::string name, int age, bool isMarried, float salary, const char* department, const char* job, std::string jobDescription, bool isManager, int noPreviousWorkingExperience, std::string* experience, int noLanguagesKnown, std::string* languagesKnown, float bonus);
	Employee(const Employee& e);

	//operator=
	Employee& operator=(const Employee& e);

	//destructor
	~Employee();

	//move constructor
	Employee(Employee&& e) noexcept;

	//setters
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
	
	//print data
	void displayInfo();

	//read data from keyboard
	friend std::istream& operator>>(std::istream& in, Employee& e);

	//write to binary files
	friend std::ofstream& operator<<(std::ofstream& outF, const Employee& e);

	//read from binary file
	friend std::ifstream& operator>>(std::ifstream& inF, Employee& e);

	//write data to text file
	void writeEmployeeToTextFile(std::ofstream& g);

	//read data from text file
	void readEmployeeFromTextFile(std::ifstream& f);

	//create a report of employees to a text file similiar with display info on the screen
	static void createTextFileReport(std::ofstream& g,const std::vector<Employee> employees);

};


