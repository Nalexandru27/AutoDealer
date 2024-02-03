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
	Employee em1("John Doe", 25, true, 2590.89, "sales", "sales representative", "Taking care of our customers needs and presents the available options", false, 2, new string[2]{ "cashier","help desk support" }, 2, new string[2]{ "romanian","english" }, 130);
	
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
	
	cout << "Employees wrote to the text file: (testing)" << endl << endl;
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
	return 0;
}