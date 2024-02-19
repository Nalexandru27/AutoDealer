#include "Car.h"
#include <stdexcept>

int Car::NO_CAR = 0;

Car::Car(const std::string vehicleIdentificationNumber) : Vehicle(vehicleIdentificationNumber) {
	Car::NO_CAR++; 
};

Car::Car(const std::string vehicleIdentificationNumber,Engine engine,Transmission transmission,DriveTrain driveTrain,int noWheels,int kilometers,std::string brand,std::string model,int manufacturerYear,bool hasAccidents,int noServices,std::vector<std::string> services,const char* color,float price,
	Category carCategory,
	const std::vector<std::string>& exteriorFeatures,
	const std::vector<std::string>& interiorFeatures,
	const std::map<int, std::string>& carOptions):
	Vehicle(vehicleIdentificationNumber, engine, transmission, driveTrain, noWheels, kilometers, brand, model, manufacturerYear, hasAccidents, noServices, services, color, price),
	category(carCategory),
	exteriorFeatures(exteriorFeatures),
	interiorFeatures(interiorFeatures),
	options(carOptions) {
	Car::NO_CAR++;
}

Car& Car::operator=(const Car& c)
{
	this->category = c.category;
	this->exteriorFeatures = c.exteriorFeatures;
	this->interiorFeatures = c.interiorFeatures;
	this->options = c.options;
	return *this;
}

Car::Car(const Car& c) :
	Vehicle(c),
	category(c.category),
	exteriorFeatures(c.exteriorFeatures),
	interiorFeatures(c.interiorFeatures),
	options(c.options) {
	Car::NO_CAR++;
}

Car::Car(Car&& other) noexcept :
	Vehicle(std::move(other)),
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

void Car::displayExteriorFeatures() {
	std::cout << std::endl << "Exterior features: ";
	for (size_t i = 0; i < this->exteriorFeatures.size(); i++) {
		std::cout << std::endl << i + 1 << ". " << this->exteriorFeatures[i];
	}
}

void Car::displayInteriorFeatures() {
	std::cout << std::endl << "Interior features: ";
	for (size_t i = 0; i < this->interiorFeatures.size(); i++) {
		std::cout << std::endl << i + 1 << ". " << this->interiorFeatures[i];
	}
}

void Car::displayOptions() {
	std::cout << std::endl << "Options: ";
	for (const auto& option : this->options) {
		std::cout << std::endl << option.first << ": " << option.second;
	}
}

void Car::Start() {
	std::cout << std::endl << "Starting the engine and the control systems...";
}

void Car::Stop() {
	std::cout << std::endl << "The engine is stop running";
}

void Car::checkSystems() {
	std::cout << std::endl << "Systems are working properly. You are ready to start your trip!";
}

void Car::readCarDataFromTxtFile(std::ifstream& in)
{
	readVehicleFromTxtFile(in);

	int aux;

	in >> aux;
	this->category = static_cast<Category>(aux);

	int limit;
	std::string s;

	in >> limit;
	in.ignore();
	for (int i = 0; i < limit; i++) {
		getline(in, s);
		this->exteriorFeatures.push_back(s);
	}

	in >> limit;
	in.ignore();
	for (int i = 0; i < limit; i++) {
		getline(in, s);
		this->interiorFeatures.push_back(s);
	}

	in >> limit;
	int key;
	for (int i = 0; i < limit; i++) {
		in >> key;
		in.ignore();
		getline(in, s);
		this->options[key] = s;
	}
}

void Car::getReport(std::ofstream& out, const std::vector<Car> cars)
{
	std::vector<Car>::const_iterator it;
	int i = 0;
	for (it = cars.begin(); it != cars.end(); ++it) {
		out << "*------------- CAR " << ++i << " STATS -------------*" << std::endl;
		out << static_cast<const Vehicle&>(*it);
		out << std::endl << "Category/type: ";
		switch ((*it).category)
		{
		case 0:
			out << "CONVERTIBLE";
			break;
		case 1:
			out << "SMALL";
			break;
		case 2:
			out << "WAGON";
			break;
		case 3:
			out << "COUPE";
			break;
		case 4:
			out << "SUV";
			break;
		case 5:
			out << "VAN";
			break;
		case 6:
			out << "LIMOUSIUNE";
		default:
			break;
		}
		out << std::endl;
		out << std::endl << "Exterior features: ";
		for (size_t i = 0; i < (*it).exteriorFeatures.size(); i++) {
			out << std::endl << i + 1 << ". " << (*it).exteriorFeatures[i];
		}
		out << std::endl << "-----------------------------------------------";
		out << std::endl << "Interior features: ";
		for (size_t i = 0; i < (*it).interiorFeatures.size(); i++) {
			out << std::endl << i + 1 << ". " << (*it).interiorFeatures[i];
		}
		out << std::endl << "-----------------------------------------------";
		out << std::endl << "Options: ";
		for (const auto& option : (*it).options) {
			out << std::endl << "Code " << option.first << ": " << option.second;
		}
		out << std::endl << std::endl << std::endl;
	}
}

void operator<<(std::ostream& out, const Car& c)
{
	out << static_cast<const Vehicle&>(c);
	out << std::endl << "Category/type: ";
	switch (c.category)
	{
	case 0:
		out << "CONVERTIBLE";
		break;
	case 1:
		out << "SMALL";
		break;
	case 2:
		out << "WAGON";
		break;
	case 3:
		out << "COUPE";
		break;
	case 4:
		out << "SUV";
		break;
	case 5:
		out << "VAN";
		break;
	case 6:
		out << "LIMOUSIUNE";
	default:
		break;
	}
	out << std::endl;
	out << std::endl << "Exterior features: ";
	for (size_t i = 0; i < c.exteriorFeatures.size(); i++) {
		out << std::endl << i + 1 << ". " << c.exteriorFeatures[i];
	}
	out << std::endl << "-----------------------------------------------";
	out << std::endl << "Interior features: ";
	for (size_t i = 0; i < c.interiorFeatures.size(); i++) {
		out << std::endl << i + 1 << ". " << c.interiorFeatures[i];
	}
	out << std::endl << "-----------------------------------------------";
	out << std::endl << "Options: ";
	for (const auto& option : c.options) {
		out << std::endl <<"Code " << option.first << ": " << option.second;
	}
	out << std::endl;
}
