#pragma once
#include <string>

enum Brands{None,MercedesBenz,Audi,Bmw};

class AutoDealer
{
private:
	std::string name = "";
	const char* address;
	Brands brand = None;
	bool hasService = false;
	int locationSize = 0;
	int parkingSlots = 0;
	std::string schedule = "";
	int chargingStations = 0;
	float rentPerMonth = 0.0f;
	//Employee* employees = nullptr;
	//Car* carsAvailable = nullptr;
public:

};

