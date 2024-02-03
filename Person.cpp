#include "Person.h"
#include "ClassUtils.h"
#include <iostream>
#include <string>
Person::Person()
{
}
Person::Person(std::string name, int age, bool isMarried) {
	if (name.size() > 6) {
		this->name = name;
	}
	else {
		throw std::exception("Name is too short");
	}
	if (age > 16 && age < 65) {
		this->age = age;
	}
	else {
		throw std::exception("Outside working age. Can't be hired");
	}
	this->isMarried = isMarried;
}

std::string Person::getName()
{
	return this->name;
}

void Person::setName(std::string name)
{
	if (name != "") {
		this->name = name;
	}
	else{
		throw std::exception("Cannot set this name");
	}
}

void Person::setAge(int age)
{
	if (age> 15 && age < 65) {
		this->age = age;
	}
	else {
		throw std::exception("Cannot set this age");
	}
}

int Person::getAge()
{
	return this->age;
}

bool Person::getIsMarried()
{
	return this->isMarried;
}

void Person::setMarried()
{
	this->isMarried = true;
}

void Person::setNotMarried()
{
	this->isMarried = false;
}

void Person::displayInfo()
{
	std::cout << std::endl << "Person name: " << this->name;
	std::cout << std::endl << "Person age: " << this->age;
	if (this->isMarried == true) {
		std::cout << std::endl << "Person is married.";
	}
	else {
		std::cout << std::endl << "Person is not married.";
	}
	std::cout << std::endl;
}

void Person::writePersonToTextFile(std::ofstream& file)
{
	file << this->name << "\n";
	file << this->age << "\n";
	file << this->isMarried << "\n";
}

void Person::writePersonToBinaryFile(std::ofstream& file) const{
	ClassUtils::serializeString(file, this->name);
	file.write((char*)&this->age, sizeof(int));
	file.write((char*)&this->isMarried, sizeof(bool));
}

void Person::readPersonFromBinaryFile(std::ifstream& file)
{
	this->name = ClassUtils::deserializeString(file);
	file.read((char*)&this->age, sizeof(int));
	file.read((char*)&this->isMarried, sizeof(bool));
}

void Person::readPersonFromTextFILE(std::ifstream& file) {
	file.ignore();
	getline(file, this->name);
	file >> this->age;
	int aux;
	file >> aux;
	aux == 1 ? this->isMarried = true : this->isMarried = false;
}


