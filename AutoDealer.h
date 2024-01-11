#pragma once
#include <string>

enum Brands{None,Mercedes,Audi,Bwm,Chevrolet,Mazda,Toyota,Tesla,LandRover,Dacia,Renault,Lexus,Volvo,Volkswagen,Porsche};

class AutoDealer
{
private:
	std::string name = "";
	const char* address;
	Brands brand = None;
	bool hasService = false;
	int perimeterSize = 0;
	int parkingSpots = 0;
	std::string schedule = "";
	int chargingStations = 0;
	//Employee* employees = nullptr;
	//Car* carsAvailable = nullptr;
public:

};

