#include "Vehicle.h"


float Vehicle::MIN_PRICE = 4999.99;

Vehicle::Vehicle(){}


Vehicle::~Vehicle()
{
	if (this->color != nullptr) {
		delete[]this->color;
		this->color = nullptr;
	}
}

Vehicle::Vehicle(const Vehicle& v)
{
	Engine::Engine(v.engine);
	this->transmission = v.transmission;
	this->driveTrain = v.driveTrain;
	this->noWheels = v.noWheels;
	this->kilometers = v.kilometers;
	this->brand = brand;
	this->model = v.model;
	this->manufactureYear = v.manufactureYear;
	this->hasAccidents = v.hasAccidents;
	this->noServices = v.noServices;
	for (int i = 0; i < this->noServices; i++) {
		service.push_back(v.service[i]);
	}
	this->color = new char[strlen(v.color) + 1];
	strcpy_s(this->color, strlen(v.color) + 1, v.color);
	this->price = v.price;
}

Vehicle& Vehicle::operator=(const Vehicle& v)
{
	Engine::Engine(v.engine);
	this->transmission = v.transmission;
	this->driveTrain = v.driveTrain;
	this->noWheels = v.noWheels;
	this->kilometers = v.kilometers;
	this->brand = v.brand;
	this->model = v.model;
	this->manufactureYear = v.manufactureYear;
	this->hasAccidents = v.hasAccidents;
	this->noServices = v.noServices;
	for (int i = 0; i < this->noServices; i++) {
		service.push_back(v.service[i]);
	}
	if (this->color != nullptr) {
		delete[]this->color;
		this->color = nullptr;
	}
	this->color = new char[strlen(v.color) + 1];
	strcpy_s(this->color, strlen(v.color) + 1, v.color);
	this->price = v.price;
	return *this;
}

Vehicle::Vehicle(const std::string vehicleIdentificationNumber, Engine engine, Transmission transmission, DriveTrain driveTrain, int noWheels, int kilometers, const std::string brand, std::string model, int manufacturerYear, bool hasAccidents, int noServices, std::string* services, const char* color, float price):vehicleIdentificationNumber(vehicleIdentificationNumber),brand(brand)
{
	this->engine = Engine(engine);
	this->transmission = transmission;
	this->driveTrain = driveTrain;
	this->noWheels = noWheels;
	this->kilometers = kilometers;
	this->model = model;
	this->manufactureYear = manufacturerYear;
	this->hasAccidents = hasAccidents;
	this->noServices = noServices;
	for (int i = 0; i < this->noServices; i++) {
		service.push_back(service[i]);
	}
	this->color = new char[strlen(color) + 1];
	strcpy_s(this->color, strlen(color) + 1, color);
	this->price = price;
}

const std::string Vehicle::getVehicleIdentificationNumber()
{
	return this->vehicleIdentificationNumber;
}

Transmission Vehicle::getTransmission()
{
	return this->transmission;
}

DriveTrain Vehicle::getDriveTrain()
{
	return this->driveTrain;
}

int Vehicle::getKm()
{
	return this->kilometers;
}

std::string Vehicle::getBrand() {
	return this->brand;
}

int Vehicle::getManufactureYear() {
	return this->manufactureYear;
}

bool Vehicle::getHasAccidents() {
	return this->hasAccidents;
}

int Vehicle::getNoServices() {
	return this->noServices;
}

std::vector<std::string> Vehicle::getServices() {
	return this->service;
}

char* Vehicle::getColor() {
	char* copy = new char[strlen(this->color) + 1];
	strcpy_s(copy, strlen(this->color) + 1, this->color);
	return copy;
}

float Vehicle::getPrice() {
	return this->price;
}

void Vehicle::setHasAccidents() {
	this->hasAccidents = true;
}

void Vehicle::setNoAccidents() {
	this->hasAccidents = false;
}

void Vehicle::setServices(int noServices, std::string* services) {
	if (noServices > 0 && services != nullptr) {
		if (!this->service.empty()) {
			this->service.clear();
		}
		this->noServices = noServices;
		for (int i = 0; i < this->noServices; i++) {
			this->service.push_back(services[i]);
		}
	}
	else {
		throw std::exception("Cannot modify the entire service list");
	}
}

void Vehicle::addService(std::string newService) {
	if (newService.size() > 5) {
		this->service.push_back(newService);
	}
	else {
		throw std::exception("Invalid service description for adding it to the service book");
	}
}

void Vehicle::setColor(const char* color) {
	if (color != nullptr && strlen(color) >= 3) {
		if (this->color != nullptr) {
			delete[]this->color;
			this->color = nullptr;
		}
		this->color = new char[strlen(color) + 1];
		strcpy_s(this->color, strlen(color) + 1, color);
	}
	else {
		throw std::exception("Color name is too short to modify the current one");
	}
}

void Vehicle::setPrice(float newPrice) {
	if (newPrice > Vehicle::MIN_PRICE) {
		this->price = newPrice;
	}
	else {
		throw std::exception("Invalid price (is too slow) for our car's price range");
	}
}

void Vehicle::Start() {
	std::cout << std::endl << "Starting the engine and the control systems...";
}

void Vehicle::Stop() {
	std::cout << std::endl << "The engine is stop running";
}

void Vehicle::checkSystems() {
	std::cout << std::endl << "Systems are working properly. You are ready to start your trip!";
}

void operator<<(std::ostream& out, const Vehicle& v)
{
	out << std::endl << "Identification number: " << v.vehicleIdentificationNumber;
	out << std::endl << v.engine;
	out << std::endl << "Transmission is: ";
	switch (v.transmission)
	{
		case 0:
			out << "Manual";
			break;
		case 1:
			out << "Semi-automatic";
			break;
		case 2:
			out << "Automatic";
			break;
		default:
			break;
	}
	out << std::endl << "Drivetrain is: ";
	switch (v.driveTrain)
	{
	case 0:
		out << "Four Wheel Drive";
		break;
	case 1:
		out << "Front Wheel Drive";
		break;
	case 2:
		out << "Rear Wheel Drive";
		break;
	default:
		break;
	}
	out << std::endl << "It has: " << v.noWheels << " wheels";
	out << std::endl << "Kilometers done: " << v.kilometers;
	out << std::endl << "Brand: " << v.brand;
	out << std::endl << "Model: " << v.model;
	out << std::endl << "Year: " << v.manufactureYear;
	v.hasAccidents == true ? out << std::endl << "Had accident" : out << std::endl << "No accident";
	out << std::endl << "It has " << v.noServices << " services done: ";
	for (int i = 0; i < v.noServices; i++) {
		out << std::endl << i + 1 << ". " << v.service[i];
	}
	out << std::endl << "Color: " << v.color;
	out << std::endl << "Price: " << v.price;
}
