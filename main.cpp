#include <iostream>
#include <fstream>
#include "Employee.h"
using namespace std;

int main() {

	try {
		Person** persons = new Person*[1];
		persons[0] = new Employee("John", 25, true, 2590.89, "sales", "sales representative", "Taking care of our customers needs and presents the available options", false, 2, new string[2]{ "cashier, help desk support" }, 2, new string[2]{ "romanian","english" }, 130);
		persons[0]->displayInfo();
	}
	catch (exception e) {
		cout << e.what();
	}
	try {
		Employee* employees1 = new Employee[1];
		for (int i = 0; i < 1; i++) {
			cin >> employees1[i];
		}
		employees1[0].displayInfo();
	}
	catch (exception e) {
		cout << e.what();
	}
	
	return 0;
}