#pragma once
#include <string>

enum Transmission {MANUAL,SEMI_AUTOMATIC, AUTOMATIC};

enum DriveTrain {FOUR_WHEEL_DRIVE, FRONT_WHEEL_DRIVE, REAR_WHEEL_DRIVE};



class Vehicle
{
protected:
	const std::string vehicleIdentificationNumber = "undefined";
	//Engine engine;
	Transmission transmission = MANUAL;
	DriveTrain driveTrain = FRONT_WHEEL_DRIVE;
	int noWheels = 0;
	int kilometers = 0;
	const std::string brand = "unknown";
	int manufactureYear = 0;
	bool hasAccidents = false;
	int noServices = 0;
	std::string* services = nullptr;
	char* color = nullptr;
	float price = 0.0f;
public:
	
	//Construtors
	Vehicle();
	Vehicle(const std::string vehicleIdentificationNumber, Transmission transmission, DriveTrain driveTrain, int noWheels, int kilometers, const std::string brand, int manufacturerYear, bool hasAccidents, int noServices, std::string* services, const char* color, float price);
	
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

	const std::string getBrand();

	int getManufactureYear();

	bool getHasAccidents();

	int getNoServices();

	std::string* getServices();

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

};

