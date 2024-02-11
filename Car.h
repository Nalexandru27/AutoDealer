#pragma once
#include "Vehicle.h"
#include <map>

enum Category {CONVERTIBLE, SMALL, WAGON, COUPE, SUV, VAN, LIMOUSINE};

class Car: public Vehicle {
private:
	Category category = SMALL;
	std::vector<std::string> exteriorFeatures;
	std::vector<std::string> interiorFeatures;
	std::map<int, std::string> options;
public:

	static int NO_CAR;

	//constructors
	Car();

	Car(const std::string vehicleIdentificationNumber, 
		Engine engine, 
		Transmission transmission, 
		DriveTrain driveTrain, 
		int noWheels, 
		int kilometers, 
		std::string brand, 
		std::string model, 
		int manufacturerYear, 
		bool hasAccidents, 
		int noServices, 
		std::vector<std::string> services,
		const char* color, 
		float price,
		Category carCategory,
		const std::vector<std::string>& exteriorFeatures,
		const std::vector<std::string>& interiorFeatures,
		const std::map<int, std::string>& carOptions);
	
	//copy constructor
	Car(const Car& c);

	//move operator
	Car(Car&& other) noexcept;

	//destructor
	~Car();

	//getters
	Category getCategory();

	std::vector<std::string> getExterior();

	std::vector<std::string> getInterior();

	std::map<int, std::string> getOptions();

	//setters
	void addOption(const int code,const std::string newOption);


	//displaying
	void displayExteriorFeatures();

	void displayInteriorFeatures();

	void displayOptions();

	void Start();

	void Stop();

	void checkSystems();

	//operator<<
	friend void operator<<(std::ostream& out, const Car& c);

	//operator cast
};

