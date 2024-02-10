#include "Car.h"
#include <stdexcept>

Car::Car() = default;

Car::Car(Category carCategory, 
	const std::vector<std::string>& exteriorFeatures, 
	const std::vector<std::string>& interiorFeatures, 
	const std::map<int, std::string>& carOptions):
	category(carCategory),
	exteriorFeatures(exteriorFeatures),
	interiorFeatures(interiorFeatures),
	options(carOptions) {}

Car::Car(const Car& c):
	category(c.category),
	exteriorFeatures(c.exteriorFeatures),
	interiorFeatures(c.interiorFeatures),
	options(c.options) {}

Car::Car(const Car&& other) noexcept :
	category(std::move(other.category)),
	exteriorFeatures(std::move(other.exteriorFeatures)),
	interiorFeatures(std::move(other.interiorFeatures)),
	options(std::move(other.options)) {}

Car::~Car() = default;

Category Car::getCategory()
{
	return this->category;
}

std::vector<std::string> Car::getExterior()
{
	return this->exteriorFeatures;
}

std::vector<std::string> Car::getInterior()
{
	return this->interiorFeatures;
}

std::map<int, std::string> Car::getOptions()
{
	return this->options;
}


void Car::addOption(const int code,const std::string newOption) {
	if (newOption.size() > 5) {
		if (code > 0) {
			options.insert({ code, newOption });
		}
		else {
			throw std::invalid_argument("Invalid option code (must be greater than 0). Try again.");
		}
	}
	else {
		throw std::invalid_argument("Invalid option length (must be greater than 5). Try again.");
	}
}

void operator<<(std::ostream& out, const Car& c)
{
	
	out << std::endl << c.category;
}
