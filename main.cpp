/*I want to design a management system for AutoDealers. Each location will have:
- specific car brand (enum)
- name (string)
- address (char*)
- service (bool)
- size of the location (int meters squared)
- parking slots (int)
- schedule (string)
- chargingStations (int)
- rent per month (float)
- employees vector ('has a' 1:M)
- cars vector ('has a' 1:M)
The app should store the data of the AutoDealer into a binary file and for the use
of user should print the data to the screen like a report and do the same for the employees
and for the cars. The app should allow the user to add/delete a new employee, add/delete a new car 
(a car is deleted when it s sold to a client). Every month will be generated a text file with the cars sold.
*/

#include <iostream>
#include <fstream>
#include "Employee.h"
#include "Engine.h"
#include "Vehicle.h"
#include <vector>
#include "Car.h"
#include "AutoDealer.h"
#include <cstdlib> 
using namespace std;

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void main() {

	int choice = -1;

	do {
		cout << "---------------AutoDealer Management System-----------------------";
		cout << endl << endl << "Menu:";
		cout << endl << "1. Discover our AutoDealer's";
		cout << endl << "2. Add a new AutoDealer";
		cout << endl << "3. Remove an AutoDealer";
		cout << endl << "Please enter your choice from the above or 0 to exit: ";

		cin >> choice;
		if (choice == 1){
			clearConsole();

			ifstream in("AutoDealers.txt");
			string temp;
			int size;
			in >> size;
			in.ignore();
			map<int, string> autoDealerOption;
			for (int i = 0; i < size; i++) {
				getline(in, temp);
				autoDealerOption[i + 1] = temp;
				cout << endl << i+1 << ". " << temp;
			}

			in.close();

			cout << endl << endl << "Please select a location with the number in front of it: ";

			cin >> choice;
			string autoDealerOptionFile = autoDealerOption[choice] + ".txt";
			ifstream read(autoDealerOptionFile);
			
			in.ignore();
			string address;
			getline(read, address);
			AutoDealer auto1(address);
			auto1.readDataAutoDealer(read);

			read.close();

			clearConsole();

			string aux;
			cout << endl << "1.1 Find details about location";
			cout << endl << "1.2 Get a text file report with the cars available";
			cout << endl << "1.3 Get a text file report with the employees";
			cout << endl << "1.4 Add a new car";
			cout << endl << "1.5 Remove a car sold";
			cout << endl << "1.6 Add a new employee";
			cout << endl << "1.7 Fire an employee";
			cout << endl << endl << "Please enter your choice (in example: 1.3) or '0' to go back: ";
			cin >> aux;
			if (aux == "0") {
				return;
			}
			else {
				if (aux == "1.1") {
					auto1.displayLocationInfo();
				}
				if (aux == "1.2") {
					string temp;
					cout << endl << "Enter name of the txt report (ex. report.txt): ";
					cin.ignore();
					cin >> temp;
					ofstream out(temp,ios::out);
					vector<Car> c;
					c = auto1.getCars();
					Car::getReport(out, c);
					cout << endl << "Report generated with success!";
				}
				if (aux == "1.3") {

				}
				if (aux == "1.4") {

				}
				if (aux == "1.5") {

				}
				if (aux == "1.6") {

				}
				if (aux == "1.7") {

				}
			}
		}
		cout << endl << "\Press 1 to continue or 0 to quit: ";
		cin >> choice;
	} while (choice != 0);

	/*Employee em2("Carl Doris", 21, false, 2545.89, "sales", "sales manager", "Taking care of our customers needs and presents the available options", true, 1, new string[1]{ "cashier" }, 3, new string[3]{ "romanian","english","french" }, 150);
	Employee em1("John Doe", 25, true, 2590.89, "sales", "sales representative", "Taking care of our customers needs and presents the available options", false, 2, new string[2]{ "cashier","help desk support" }, 2, new string[2]{ "romanian","english" }, 130);
	
	string temp;
	ifstream file("CarData.txt");
	std::vector<Car> cars;
	for (int i = 0; i < 3; i++) {
		file >> temp;
		Car c1(temp);
		c1.readCarDataFromTxtFile(file);
		cars.push_back(c1);
	}
	file.close();
	vector<Employee> employees;
	employees.push_back(em1);
	AutoDealer a1("G&C AutoDealer", "Splaiul Unirii 25", true, 10000, 25, "9:00-19:00", 10, 15000, employees, cars);		
	ofstream outF("G&C AutoDealer.txt", ios::out);
	a1.displayTxtFile(outF);*/
}
