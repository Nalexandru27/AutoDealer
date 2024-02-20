#pragma once
#include <string>
#include "Employee.h"
#include "Car.h"
#include <vector>
class AutoDealer
{
private:
	std::string name = " ";
	const std::string address = "none";
	bool hasService = false;
	int locationSize = 0;
	int parkingSlots = 0;
	std::string schedule = " ";
	int chargingStations = 0;
	int rentPerMonth = 0;
	std::vector<Employee>employees;
	std::vector<Car> cars;
public:
	//default constructor
	AutoDealer(const std::string);

	//constructor
	AutoDealer(std::string name, 
		const std::string address, 
		bool hasService, 
		int locationSize, 
		int parkingSlots, 
		std::string schedule, 
		int chargingStations, 
		int rentPerMonth, 
		std::vector<Employee>employees, 
		std::vector<Car> cars);

	//copy constructor
	AutoDealer(const AutoDealer& source);

	//operator=
	AutoDealer& operator=(const AutoDealer& source);

	//destructor
	~AutoDealer();

	//getters
	std::string getName();

	const std::string getAddress();

	bool getHasService();

	int getLocationSize();

	int getParkingSlots();

	std::string getSchedule();

	int getChargingStations();

	int getRentPerMonth();

	const std::vector<Employee> getEmployees() const;

	const std::vector<Car> getCars() const;

	//setters
	void setName(std::string newName);

	void ServiceTrue();

	void ServiceFalse();

	void setLocationSize(int newSize);

	void setParkingSlots(int newParkingSlots);

	void setSchedule(std::string newSchedule);

	void setChargingStations(int newChargingStations);

	void setRentPerMonth(int newRentPerMonth);

	void setEmployees(std::vector<Employee> employees);

	void setCars(std::vector<Car> cars);

	//add a new car
	void addCar(const Car& car);

	//remove car (sold)
	void removeCar(size_t index);

	//add new employee
	void addEmployee(const Employee& employee);

	//remove employee (fired)
	void removeEmployee(size_t id);

	//generate report into a text file
	void displayTxtFile(std::ofstream& out);
};

