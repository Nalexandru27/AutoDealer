#pragma once
#include <string>
#include "Engine.h"
#include <vector>
#include <algorithm>
#include <fstream>

enum Transmission {MANUAL,SEMI_AUTOMATIC, AUTOMATIC};

enum DriveTrain {FOUR_WHEEL_DRIVE, FRONT_WHEEL_DRIVE, REAR_WHEEL_DRIVE};

class Vehicle
{
protected:
	const std::string vehicleIdentificationNumber = "undefined";
	Engine engine;
	Transmission transmission = MANUAL;
	DriveTrain driveTrain = FRONT_WHEEL_DRIVE;
	int noWheels = 0;
	int kilometers = 0;
	std::string brand = "unknown";
	std::string model = "unknown";
	int manufactureYear = 0;
	bool hasAccidents = false;
	int noServices = 0;
	std::vector<std::string> service;
	char* color = nullptr;
	float price = 0.0f;

public:

	static float MIN_PRICE;

	//Construtors
	Vehicle(const std::string vehicleIdentificationNumber);
	Vehicle(const std::string vehicleIdentificationNumber, Engine engine, Transmission transmission, DriveTrain driveTrain, int noWheels, int kilometers, std::string brand, std::string model, int manufacturerYear, bool hasAccidents, int noServices, std::vector<std::string> service, const char* color, float price);
	
	//Destructor
	~Vehicle();

	//Copy construtor
	Vehicle(const Vehicle& v);

	//operator=
	Vehicle& operator=(const Vehicle& v);

	//getters
	const std::string getVehicleIdentificationNumber();

	Transmission getTransmission();

	DriveTrain getDriveTrain();

	int getKm();

	std::string getBrand();

	int getManufactureYear();

	bool getHasAccidents();

	int getNoServices();

	std::vector<std::string> getServices();
	
	char* getColor();

	float getPrice();

	//setters
	void setHasAccidents();
	
	void setNoAccidents();

	void setServices(int noServices, std::string* services);

	void addService(std::string newService);

	void setColor(const char* newColor);

	void setPrice(float newPrice);

	virtual void Start() = 0;

	virtual void Stop() = 0;

	virtual void checkSystems() = 0;

	//operator<<
	friend void operator<<(std::ostream& out, const Vehicle& v);

	//read from text file
	void readVehicleFromTxtFile(std::ifstream& in);

	//write to text file
};

