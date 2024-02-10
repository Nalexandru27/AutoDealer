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
	//constructors
	Car();

	Car(Category carCategory,
		const std::vector<std::string>& exteriorFeatures,
		const std::vector<std::string>& interiorFeatures,
		const std::map<int, std::string>& carOptions);
	
	//copy constructor
	Car(const Car& c);

	//move operator
	Car(const Car&& other) noexcept;

	//destructor
	~Car();

	//getters
	Category getCategory();

	std::vector<std::string> getExterior();

	std::vector<std::string> getInterior();

	std::map<int, std::string> getOptions();

	//setters
	void addOption(const int code,const std::string newOption);

	//operator<<
	friend void operator<<(std::ostream& out, const Car& c);

	//operator cast
};

