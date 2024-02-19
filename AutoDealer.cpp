#include "AutoDealer.h"

void AutoDealer::setName(std::string newName)
{
	if (newName.size() > 10) {
		this->name = newName;
	}
	else {
		throw std::exception("New name is too short!");
	}
}

void AutoDealer::ServiceTrue()
{
	this->hasService = true;
}

void AutoDealer::ServiceFalse()
{
	this->hasService = false;
}

void AutoDealer::setLocationSize(int newSize)
{
	if (newSize > 0 && newSize >= this->locationSize / 2) {
		this->locationSize = newSize;
	}
	else {
		throw std::exception("New location size must be positive and at least half of the original size");
	}
}

void AutoDealer::setParkingSlots(int newParkingSlots)
{
	if (newParkingSlots > 0 && newParkingSlots >= this->parkingSlots / 2) {
		this->parkingSlots = newParkingSlots;
	}
	else {
		throw std::exception("New parking slots should be positive and at least half of the original value");
	}
}

void AutoDealer::setSchedule(std::string newSchedule)
{
	if (newSchedule.size() >= 10) {
		this->schedule = newSchedule;
	}
	else {
		throw std::exception("New schedule should be of HH:MM-HH:MM format");
	}
}

void AutoDealer::setChargingStations(int newChargingStations)
{
	if (newChargingStations > 0 && newChargingStations > this->chargingStations) {
		this->chargingStations = newChargingStations;
	}
	else {
		throw std::exception("New no of charging stations should be positive and bigger than the current value");
	}
}

void AutoDealer::setRentPerMonth(int newRentPerMonth)
{
	if (newRentPerMonth > 0) {
		this->rentPerMonth = newRentPerMonth;
	}
	else {
		throw std::exception("New rent per month must be positive");
	}
}

void AutoDealer::setEmployees(std::vector<Employee> employees)
{
	if (employees.size() >= 1) {
		this->employees = employees;
	}
	else {
		throw std::exception("No of employees should be at least one");
	}
}

void AutoDealer::setCars(std::vector<Car> cars)
{
	if (cars.size() > 2) {
		this->cars = cars;
	}
	else {
		throw std::exception("AutoDealer must have at least 2 cars available");
	}
}

void AutoDealer::addCar(const Car& car)
{
	this->cars.push_back(car);
}

void AutoDealer::removeCar(size_t index)
{
	if (index >= 0 && index < this->cars.size()) {
		cars.erase(cars.begin() + index);
		std::cout << std::endl << "Car number " << index + 1 << " deleted (sold)";
	}
	else {
		throw std::exception("Index out of bounds. Cannot delete");
	}
}

void AutoDealer::addEmployee(const Employee& employee)
{
	this->employees.push_back(employee);
}

AutoDealer::AutoDealer(const std::string):address(address) {}

AutoDealer::AutoDealer(std::string name, const std::string, bool hasService, int locationSize, int parkingSlots, std::string schedule, int chargingStations, int rentPerMonth, std::vector<Employee> employees, std::vector<Car> cars):address(address)
{
	setName(name);
	this->hasService = hasService;
	setLocationSize(locationSize);
	setParkingSlots(parkingSlots);
	setSchedule(schedule);
	setChargingStations(chargingStations);
	setRentPerMonth(rentPerMonth);
	setEmployees(employees);
	setCars(cars);
}

AutoDealer::AutoDealer(const AutoDealer& source):address(source.address)
{
	setName(source.name);
	this->hasService = source.hasService;
	setLocationSize(source.locationSize);
	setParkingSlots(source.parkingSlots);
	setSchedule(source.schedule);
	setChargingStations(source.chargingStations);
	setRentPerMonth(source.rentPerMonth);
	setEmployees(source.employees);
	setCars(source.cars);
}

AutoDealer& AutoDealer::operator=(const AutoDealer& source)
{
	setName(source.name);
	this->hasService = source.hasService;
	setLocationSize(source.locationSize);
	setParkingSlots(source.parkingSlots);
	setSchedule(source.schedule);
	setChargingStations(source.chargingStations);
	setRentPerMonth(source.rentPerMonth);
	setEmployees(source.employees);
	setCars(source.cars);
	return *this;
}

AutoDealer::~AutoDealer() = default;

std::string AutoDealer::getName()
{
	return this->name;
}

const std::string AutoDealer::getAddress()
{
	return this->address;
}

bool AutoDealer::getHasService()
{
	return this->hasService;
}

int AutoDealer::getLocationSize()
{
	return this->locationSize;
}

int AutoDealer::getParkingSlots()
{
	return this->parkingSlots;
}

std::string AutoDealer::getSchedule()
{
	return this->schedule;
}

int AutoDealer::getChargingStations()
{
	return this->chargingStations;
}

int AutoDealer::getRentPerMonth()
{
	return rentPerMonth;
}

const std::vector<Employee> AutoDealer::getEmployees() const
{
	return this->employees;
}

const std::vector<Car> AutoDealer::getCars() const
{
	return this->cars;
}


