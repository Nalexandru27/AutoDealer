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

void AutoDealer::displayLocationInfo()
{
	std::cout << std::endl << "Address is: " << this->address;
	std::cout << std::endl << "Name is: " << this->name;
	this->hasService == 1 ? std::cout << std::endl << "Has Service" : std::cout << std::endl << "Does not have a service";
	std::cout << std::endl << "Location size: " << this->locationSize;
	std::cout << std::endl << "Parking Slots: " << this->parkingSlots;
	std::cout << std::endl << "Schedule: " << this->schedule;
	std::cout << std::endl << "Charging Stations: " << this->chargingStations;
	std::cout << std::endl << "Rent per month: " << this->rentPerMonth;
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

void AutoDealer::readDataAutoDealer(std::ifstream& in) {
	getline(in, this->name);
	in >> this->hasService;
	in >> this->locationSize;
	in >> this->parkingSlots;
	in.ignore();
	in >> this->schedule;
	in >> this->chargingStations;
	in >> this->rentPerMonth;
	int noEmployees;
	in >> noEmployees;
	for (int i = 0; i < noEmployees; i++) {
		Employee temp;
		in.ignore();
		temp.readEmployeeFromTextFile(in);
		this->employees.push_back(temp);
	}
	int noCars;
	in >> noCars;
	std::string vehicleId;
	for (int i = 0; i < noCars; i++) {
		in >> vehicleId;
		Car temp(vehicleId);
		in.ignore();
		temp.readCarDataFromTxtFile(in);
		this->cars.push_back(temp);
	}
}

void AutoDealer::displayTxtFile(std::ofstream& out)
{
	out << "|  Welcome to " << this->name << " AutoDealer  |" << std::endl;
	out << std::endl << "Our address is: " << this->address;
	this->hasService == true ? out << std::endl << "We offer auto service" : out << std::endl << "We don't have a service auto";
	out << std::endl << "This location is: " << this->locationSize << " meters squared";
	out << std::endl << "This location has: " << this->parkingSlots << " parking slots";
	out << std::endl << "Schedule hours is: " << this->schedule;
	out << std::endl << "This location has: " << this->chargingStations << " chargings stations for electric cars";
	out << std::endl << "Rent per month is: " << this->rentPerMonth << " euro";
	Employee::createTextFileReport(out, employees);
	Car::getReport(out, cars);
	out << std::endl << std::endl;
}

AutoDealer::AutoDealer(const std::string address):address(address) {}

AutoDealer::AutoDealer(std::string name, const std::string address, bool hasService, int locationSize, int parkingSlots, std::string schedule, int chargingStations, int rentPerMonth, std::vector<Employee> employees, std::vector<Car> cars):address(address)
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
	this->employees = source.employees;
	this->cars = source.cars;
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


