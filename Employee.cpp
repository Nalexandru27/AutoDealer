#include "Employee.h"
#include<iostream>
#include <fstream>
Employee::Employee()
{

}

Employee::Employee(std::string name, int age, bool isMarried, float salary, const char* department, const char* job, std::string jobDescription, bool isManager, int noPreviousWorkingExperience, std::string* experience, int noLanguagesKnown, std::string* languagesKnown, float bonus)
{
	setName(name);
	setAge(age);
	this->isMarried = isMarried;
	setSalary(salary);
	setDepartment(department);
	setJob(job);
	setJobDescription(jobDescription);
	this->isManager = isManager;
	setExperience(noPreviousWorkingExperience, experience);
	setLanguagesKnown(noLanguagesKnown, languagesKnown);
	setBonus(bonus);
}

Employee::Employee(const Employee& e)
{
	setName(e.name);
	setAge(e.age);
	this->isMarried = e.isMarried;
	setSalary(e.salary);
	setDepartment(e.department);
	setJob(e.job);
	setJobDescription(e.jobDescription);
	this->isManager = e.isManager;
	setExperience(e.noPreviousWorkingExperience, e.experience);
	setLanguagesKnown(e.noLanguagesKnown, e.languagesKnown);
	setBonus(e.bonus);
}

Employee& Employee::operator=(const Employee& e)
{
	setName(e.name);
	setAge(e.age);
	this->isMarried = e.isMarried;
	setSalary(e.salary);
	setDepartment(e.department);
	setJob(e.job);
	setJobDescription(e.jobDescription);
	this->isManager = e.isManager;
	setExperience(e.noPreviousWorkingExperience, e.experience);
	setLanguagesKnown(e.noLanguagesKnown, e.languagesKnown);
	setBonus(e.bonus);
	return *this;
}

Employee::~Employee()
{
	if (this->department != nullptr) {
		delete[]this->department;
		this->department = nullptr;
	}
	if (this->job != nullptr) {
		delete[]this->job;
		this->job = nullptr;
	}
	if (this->experience != nullptr) {
		delete[]this->experience;
		this->experience = nullptr;
	}
	if (this->languagesKnown != nullptr) {
		delete[]this->languagesKnown;
		this->languagesKnown = nullptr;
	}
}

void Employee::setSalary(float salary)
{
	if (salary > 0) {
		this->salary = salary;
	}
	else {
		throw std::exception("Cannot set this salary");
	}
}

void Employee::setDepartment(const char* department)
{
	if (strlen(department) > 0) {
		if (this->department != nullptr) {
			delete[] this->department;
			this->department = nullptr;
		}
		this->department = new char[strlen(department) + 1];
		strcpy_s(this->department, strlen(department) + 1, department);
	}
	else {
		throw std::exception("Cannot set this department");
	}
}

void Employee::setJob(const char* job)
{
	if (strlen(job) > 0) {
		if (this->job != nullptr) {
			delete[] this->job;
			this->job = nullptr;
		}
		this->job = new char[strlen(job) + 1];
		strcpy_s(this->job, strlen(job) + 1, job);
	}
	else {
		throw std::exception("Cannot set this job");
	}
}

void Employee::setJobDescription(std::string jobDescription)
{
	if (jobDescription.size() > 10) {
		this->jobDescription = jobDescription;
	}
	else {
		throw std::exception("Cannot set this job description");
	}
}

void Employee::setIsManager()
{
	this->isManager = true;
}

void Employee::setIsNotManager()
{
	this->isManager = false;
}


void Employee::setExperience(int value, std::string* experience)
{
	if (experience != nullptr && value > 0 ) {
		if (this->experience != nullptr) {
			delete[]this->experience;
			this->experience = nullptr;
		}
		this->experience = new std::string[value];
		for (int i = 0; i < value; i++) {
			this->experience[i] = experience[i];
		}
		this->noPreviousWorkingExperience = value;
	}
	else {
		throw std::exception("Cannot set this working experience");
	}
}

void Employee::setLanguagesKnown(int value, std::string* languagesKnown)
{
	if (languagesKnown != nullptr && value > 0) {
		if (this->languagesKnown != nullptr) {
			delete[]this->languagesKnown;
			this->languagesKnown = nullptr;
		}
		this->languagesKnown = new std::string[value];
		for (int i = 0; i < value; i++) {
			this->languagesKnown[i] = languagesKnown[i];
		}
		delete[] languagesKnown;
		this->noLanguagesKnown = value;
	}
	else {
		throw std::exception("Cannot set this languages spoken");
	}
}

void Employee::setBonus(float bonus)
{
	if (bonus > 0) {
		this->bonus = bonus;
	}
	else {
		throw std::exception("Cannot set this bonus");
	}
}

void Employee::addJobDescription(std::string description)
{
	if (description.size() > 10) {
		this->jobDescription = description;
	}
	else {
		throw std::exception("Cannot modify the job description with the new one");
	}
}

void Employee::addExperience(std::string experience)
{
	if (this->experience != nullptr && experience != "") {
		std::string* temp = new std::string[this->noPreviousWorkingExperience+1];
		for (int i = 0; i < this->noPreviousWorkingExperience; i++) {
			temp[i] = this->experience[i];
		}
		temp[this->noPreviousWorkingExperience] = experience;
		this->noPreviousWorkingExperience++;
		delete[]this->experience;
		this->experience = temp;
	}
	else if(experience != ""){
		this->experience = new std::string[1];
		this->experience[0] = experience;
		this->noPreviousWorkingExperience++;
	}
}

void Employee::displayInfo()
{
	Person::displayInfo();
	std::cout << std::endl << "Employee salary is: " << this->salary <<" ron";
	std::cout << std::endl << "Employee is working at " << this->department << ".";
	std::cout << std::endl << "Employee's job is: " << this->job;
	std::cout << std::endl << "Job description is: " << this->jobDescription;
	if (this->isManager == true) {
		std::cout << std::endl << "Employee is a manager.";
	}
	else {
		std::cout << std::endl << "Employee is not a manager.";
	}
	std::cout << std::endl << "Employee had " << this->noPreviousWorkingExperience << " previous working experiences: ";
	for (int i = 0; i < this->noPreviousWorkingExperience; i++) {
		std::cout << std::endl << i+1 << "." << this->experience[i];
	}
	std::cout << std::endl << "Employee speaks " << this->noLanguagesKnown << " languages: ";
	std::cout << this->languagesKnown[0];
	for (int i = 1; i < this->noLanguagesKnown; i++) {
		std::cout << ", " << this->languagesKnown[i];
	}
	std::cout << std::endl << "Employee will receive a bonus of: " << this->bonus << " ron";
	std::cout << std::endl;

}

std::istream& operator>>(std::istream& in, Employee& e)
{
	float salary;
	std::cout << std::endl << "What is the salary of the employee? ";
	in >> salary;
	e.setSalary(salary);
	char buffer[100];
	in.ignore();
	std::cout << std::endl << "In which department does he/she work? ";
	in.getline(buffer, 100);
	e.setDepartment(buffer);
	std::cout << std::endl << "What is her/his job? ";
	//in.ignore();
	in.getline(buffer, 100);
	e.setJob(buffer);
	std::string s;
	std::cout << std::endl << "Describe the duties of this job: ";
	getline(in, s);
	e.setJobDescription(s);
	std::cout << std::endl << "Is she/he a manager?(yes/no) ";
	in >> s;
	if (s == "yes") {
		e.setIsManager();
	}
	else if(s == "no"){
		e.setIsNotManager();
	}
	int value;
	std::cout << std::endl << "How many job experience did she/he has before? ";
	in >> value;
	in.ignore();
	if (value > 0) {
		std::string* experience = new std::string[value];
		for (int i = 0; i < value; i++) {
			std::cout << std::endl << "Enter job description " << i <<": ";
			getline(in, s);
			if (s.size() > 5) {
				experience[i] = s;
			}
		}
		e.setExperience(value, experience);
	}
	else {
		throw std::exception("Cannot read this value for numbers of previous work experience");
	}
	std::cout << std::endl << "How many languages does she/he know? ";
	in >> value;
	in.ignore();
	if (value > 0) {
		std::string* languages = new std::string[value];
		for (int i = 0; i < value; i++) {
			std::cout << std::endl << "Enter language " << i << " spoken: ";
			getline(in, s);
			if (s.size() > 3) {
				languages[i] = s;
			}
		}
		e.setLanguagesKnown(value, languages);
	}
	else {
		throw std::exception("Cannot read this value for languages known, must be positive");
	}
	float f;
	std::cout << std::endl << "Enter bonus earnings for this employee: ";
	in >> f;
	if (f >= 0) {
		e.bonus = f;
	}
	else {
		throw std::exception("Cannot read a negative bonus");
	}
	return in;
}

std::ofstream& operator<<(std::ofstream& outF,const Employee& e) {
	e.writePersonToBinaryFile(outF);
	outF.write((char*)&e.salary, sizeof(float));
	ClassUtils::serializeChar(outF, e.department);
	ClassUtils::serializeChar(outF, e.job);
	ClassUtils::serializeString(outF, e.jobDescription);
	outF.write((char*)&e.isManager, sizeof(bool));
	outF.write((char*)&e.noPreviousWorkingExperience, sizeof(int));
	for (int i = 0; i < e.noPreviousWorkingExperience; i++) {
		ClassUtils::serializeString(outF, e.experience[i]);
	}
	outF.write((char*)&e.noLanguagesKnown, sizeof(int));
	for (int i = 0; i < e.noLanguagesKnown; i++) {
		ClassUtils::serializeString(outF, e.languagesKnown[i]);
	}
	outF.write((char*)&e.bonus, sizeof(float));
	return outF;
}

std::ifstream& operator>>(std::ifstream& inF, Employee& e)
{
	e.readPersonFromBinaryFile(inF);
	inF.read((char*)&e.salary, sizeof(float));
	ClassUtils::deserializeChar(inF, e.department);
	ClassUtils::deserializeChar(inF, e.job);
	e.jobDescription = ClassUtils::deserializeString(inF);
	inF.read((char*)&e.isManager, sizeof(bool));

	inF.read((char*)&e.noPreviousWorkingExperience, sizeof(int));
	if (e.experience != nullptr) {
		delete[]e.experience;
		e.experience = nullptr;
	}
	e.experience = new std::string[e.noPreviousWorkingExperience];
	for (int i = 0; i < e.noPreviousWorkingExperience; i++) {
		e.experience[i] = ClassUtils::deserializeString(inF);
	}

	inF.read((char*)&e.noLanguagesKnown, sizeof(int));
	if (e.languagesKnown != nullptr) {
		delete[]e.languagesKnown;
		e.languagesKnown = nullptr;
	}
	e.languagesKnown = new std::string[e.noLanguagesKnown];
	for (int i = 0; i < e.noLanguagesKnown; i++) {
		e.languagesKnown[i] = ClassUtils::deserializeString(inF);
	}

	inF.read((char*)&e.bonus, sizeof(float));
	return inF;
}


void Employee::writeEmployeeToTextFile(std::ofstream& g)
{
	writePersonToTextFile(g);
	g << this->salary << "\n";
	g << this->department << "\n";
	g << this->job << "\n";
	g << this->jobDescription << "\n";
	g << this->isManager << "\n";
	g << this->noPreviousWorkingExperience << "\n";
	for (int i = 0; i < this->noPreviousWorkingExperience; i++) {
		g << this->experience[i] << "\n";
	}
	g << this->noLanguagesKnown << "\n";
	for (int i = 0; i < this->noLanguagesKnown; i++) {
		g << this->languagesKnown[i] << "\n";
	}
	g << this->bonus << "\n";
}

void Employee::readEmployeeFromTextFile(std::ifstream& f) {
	
	Person::readPersonFromTextFILE(f);

	f >> this->salary;

	if (this->department != nullptr) {
		delete[]this->department;
		this->department = nullptr;
	}
	char buffer[100];
	f.ignore();
	f.getline(buffer, 100);
	this->department = new char[strlen(buffer) + 1];
	strcpy_s(this->department, strlen(buffer) + 1, buffer);

	if (this->job != nullptr) {
		delete[]this->job;
		this->job = nullptr;
	}
	f.getline(buffer, 100);
	this->job = new char[strlen(buffer) + 1];
	strcpy_s(this->job, strlen(buffer) + 1, buffer);

	getline(f, this->jobDescription);

	int aux; 
	f >> aux;
	aux == 1 ? setIsManager() : setIsNotManager();

	if (this->experience != nullptr) {
		delete[]this->experience;
		this->experience = nullptr;
	}
	f >> this->noPreviousWorkingExperience;
	f.ignore();
	this->experience = new std::string[this->noPreviousWorkingExperience];
	for (int i = 0; i < this->noPreviousWorkingExperience; i++) {
		getline(f, this->experience[i]);
	}

	if (this->languagesKnown != nullptr) {
		delete[]this->languagesKnown;
		this->languagesKnown = nullptr;
	}
	f >> this->noLanguagesKnown;
	f.ignore();
	this->languagesKnown = new std::string[this->noLanguagesKnown];
	for (int i = 0; i < this->noLanguagesKnown; i++) {
		getline(f, this->languagesKnown[i]);
	}

	f >> this->bonus;

	f.ignore();
}

void Employee::createTextFileReport(std::ofstream& g, int noEmployees, Employee* employeeArray)
{
	if (employeeArray != nullptr && noEmployees > 0) {
		for (int i = 0; i < noEmployees; i++) {
			g << "Employee " << i + 1 << ": " << employeeArray[i].name << "\n";
			g << "Age: " << employeeArray[i].age << "\n";
			employeeArray[i].isMarried ? g << "Is married\n": g << "Is not married\n";
			g << "Salary: " << employeeArray[i].salary << "\n";
			g << "Working in " << employeeArray[i].department << " department" << "\n";
			g << "Job profile: " << employeeArray[i].job << "\n";
			g << "Job responsabilities: " << employeeArray[i].jobDescription << "\n";
			employeeArray[i].isManager ? g << "Is manager\n" : g << "Is not manager\n";
			g << "Number of previous working experiences: " << employeeArray[i].noPreviousWorkingExperience << "\n";
			for (int j = 0; j < employeeArray[i].noPreviousWorkingExperience; j++) {
				g << j+1 << ". " << employeeArray[i].experience[j] << "\n";
			}
			g << "Number of languages known: " << employeeArray[i].noLanguagesKnown << "\n";
			for (int k = 0; k < employeeArray[i].noLanguagesKnown; k++) {
				g << "- " << employeeArray[i].languagesKnown[k] << "\n";
			}
			g << "Monthly bonus: " << employeeArray[i].bonus << "\n";
			g << "\n\n";
		}
	}
	else {
		throw std::exception("Couldn't create the report with the employees");
	}
}

