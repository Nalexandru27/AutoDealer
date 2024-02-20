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

using namespace std;


int main() {

	/*try {
		Person** persons = new Person*[1];
		persons[0] = new Employee("John", 25, true, 2590.89, "sales", "sales representative", "Taking care of our customers needs and presents the available options", false, 2, new string[2]{ "cashier","help desk support" }, 2, new string[2]{ "romanian","english" }, 130);
		persons[0]->displayInfo();
	}
	catch (exception e) {
		cout << e.what();
	}*/
	/*try {
		Employee* employees1 = new Employee[1];
		for (int i = 0; i < 1; i++) {
			cin >> employees1[i];
		}
		employees1[0].displayInfo();
	}
	catch (exception e) {
		cout << e.what();
	}*/
	/*Person person1("John Doe", 28, false);
	std::ofstream textFile("report.txt", std::ios::out);
	if (!textFile.is_open()) {
		return -1;
	}
	else {
		person1.writePersonToTextFile(textFile);
	}*/	
	/*ofstream oBinFile("Employees.bin", ios::binary | ios::out);
	oBinFile << em1;
	oBinFile.close();

	Employee em2;
	ifstream iBinFile("Employees.bin", ios::binary | ios::in);
	iBinFile >> em2;
	em2.displayInfo();
	iBinFile.close();
	
	Person person1("John Doe", 28, false);
	ofstream g("Person.txt");
	person1.writePersonToTextFile(g);
	g.close();*/
	
	/*cout << "Employees wrote to the text file: (testing)" << endl << endl;
	em1.displayInfo();
	cout << endl << endl;
	Employee em2("Carl Doris", 21, false, 2545.89, "sales", "sales manager", "Taking care of our customers needs and presents the available options", true, 1, new string[1]{ "cashier" }, 3, new string[3]{ "romanian","english","french" }, 150);
	em2.displayInfo();
	cout << endl << endl << endl;

	ofstream wTextFile("Employees.txt");
	em1.writeEmployeeToTextFile(wTextFile);
	em2.writeEmployeeToTextFile(wTextFile);
	wTextFile.close();

	ifstream rTextFile("Employees.txt");
	Employee em3, em4;
	em3.readEmployeeFromTextFile(rTextFile);
	em4.readEmployeeFromTextFile(rTextFile);
	rTextFile.close();

	cout << "Employees read from the text file: (testing)" << endl << endl;
	em3.displayInfo();
	cout << endl << endl;
	em4.displayInfo();
	cout << endl << endl << endl;

	ifstream rBinFile("Employees.bin", ios::binary | ios::in);
	Employee em5;
	rBinFile >> em5;
	cout << endl << endl << "Displaying a employee read from a bin file: (testing)";
	em5.displayInfo();
	rBinFile.close();

	ofstream WTextFile("EmployeesRegister.txt");
	em5.writeEmployeeToTextFile(WTextFile);


	ifstream textFile("Employees.txt");
	Employee* employees = new Employee[2];
	for (int i = 0; i < 2; i++) {
		employees[i].readEmployeeFromTextFile(textFile);
	}
	textFile.close();
	ofstream textFile2("EmployeesReport.txt");
	Employee::createTextFileReport(textFile2,2,employees);
	textFile2.close();*/

	Engine e1(115, 260, 4, 1.5, false, "d15",PETROL);
	//cout << e1;
	//cout << endl;
	//e1 += 15;
	//cout << e1;

	//int a = e1;
	//cout << endl << a << endl;
	//cout << e1();

	//vector<int> v1 = { 1,4,2,6,2 };
	//v1.clear();
	//cout << endl;
	//for (int i = 0; i < v1.size(); i++) {
	//	cout << v1[i] << " ";
	//}
	
	/*Car c1("AB141ASFK", e1, AUTOMATIC, FOUR_WHEEL_DRIVE, 4, 60000, "Mercedes", "Class C", 2015, true, 2,{"Oil change", "Brakes change"}, "Green elmerald", 16999.99, COUPE, { "Spoiler","19's wheels" }, { "Black leather","Electric seats" }, { {3053,"Apple Car Play Wifi"},{4210,"Security Alarm"} });
	
	cout << endl << endl;
	cout << c1;


	std::ifstream eng("Engine.txt", ios::in);
	if (!eng.is_open()) {
		std::cerr << "Error opening file: Engine.txt" << std::endl;
	}
	Engine e4;
	e4.readFromTextFile(eng);
	cout << endl << endl << e4;*/

	//Vehicle v1("JMD1KMF428AUYV4");
	//ifstream inFile("VehicleInputFile.txt");
	//if (!inFile.is_open()) {
	//	std::cerr << "Error opening file: Engine.txt" << std::endl;
	//}
	//v1.readVehicleFromTxtFile(inFile);
	//cout << v1;

	/*Car c1("J1U831MBAU15AKN");
	ifstream file("CarData.txt");
	c1.readCarDataFromTxtFile(file);
	cout << c1;*/
	/*Employee em1("John Doe", 25, true, 2590.89, "sales", "sales representative", "Taking care of our customers needs and presents the available options", false, 2, new string[2]{ "cashier","help desk support" }, 2, new string[2]{ "romanian","english" }, 130);

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

	ofstream File("CarReport.txt", ios::out);
	Car::getReport(File, cars);
	File.close();

	vector<Employee> employees;
	employees.push_back(em1);*/
	
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
		
		ofstream outF("AutoDealer1.txt", ios::out);
		a1.displayTxtFile(outF);


	return 0;
}
