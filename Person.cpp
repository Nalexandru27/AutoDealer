#include "Person.h"
#include <iostream>
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
}

