#pragma once
#include <string>
#include "Employee.h"
#include "Car.h"
#include <vector>
class AutoDealer
{
private:
	std::string name = "";
	const char* address;
	bool hasService = false;
	int locationSize = 0;
	int parkingSlots = 0;
	std::string schedule = "";
	int chargingStations = 0;
	float rentPerMonth = 0.0f;
	int noEmployees = 0;
	std::vector<Employee>employees;
	std::vector<Car> cars;
public:

};

