#pragma once
#include <string>
#include "Employee.h"
#include "Car.h"
#include <vector>
class AutoDealer
{
private:
	std::string name = "";
	const char* address;
	bool hasService = false;
	int locationSize = 0;
	int parkingSlots = 0;
	std::string schedule = "";
	int chargingStations = 0;
	int rentPerMonth = 0;
	int noEmployees = 0;
	std::vector<Employee>employees;
	std::vector<Car> cars;
public:
	//default constructor
	AutoDealer(const char* address);

	//constructor
	AutoDealer(std::string name, 
		const char* address, 
		bool hasService, 
		int locationSize, 
		int parkingSlots, 
		std::string schedule, 
		int chargingStations, 
		int rentPerMonth, 
		int noEmployees,
		std::vector<Employee>employees, 
		std::vector<Car> cars);

	//copy constructor
	AutoDealer(const AutoDealer& source);

	//operator=
	AutoDealer operator=(const AutoDealer& source);

	//destructor
	~AutoDealer();

	//getters
	std::string getName();

	const char* getAddress();

	bool getHasService();

	int getLocationSize();

	int getParkingSlots();

	std::string getSchedule();

	int getChargingStations();

	int getRentPerMonth();

	int getNoEmployees();

	std::vector<Employee> getEmployees();

	std::vector<Car> getCars();

	//setters
	void setName(std::string newName);

	void hasService();

	void hasNoService();

	void setLocationSize(int newSize);

	void setParkingSlots(int newParkingSlots);

	void setSchedule(std::string newSchedule);

	void setChargingStations(int newChargingStations);

	void setRentPerMonth(int newRentPerMonth);

	void setEmployees(int noEmployees, std::vector<Employee> employees);

	void setCars(int noCars, std::vector<Car> cars);

	//add a new car
	void addCar(const Car& car);

	//remove car (sold)
	void removeCar(int index);

	//add new employee
	void addEmployee(const Employee& employee);

	//remove employee (fired)
	void removeEmployee(int id);
};

