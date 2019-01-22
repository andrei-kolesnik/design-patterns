/*
Dependency inversion principle
https://en.wikipedia.org/wiki/Dependency_inversion_principle
A. High-level modules should not depend on low-level modules. Both should depend on abstractions.
B. Abstractions should not depend on details. Details should depend on abstractions.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EmailNotification {
public:
	void SendNotification(string name) {
		cout << "Email Notification sent to " << name << endl;
	}
};

class TextNotification {
public:
	void SendNotification(string name) {
		cout << "Text Notification sent to " << name << endl;
	}
};

int main() {
	// somewhere is our application:
	EmailNotification emailer1;
	emailer1.SendNotification("Person 1");

	// somewhere else is our application:
	EmailNotification emailer2;
	emailer2.SendNotification("Person 2");

	// Now if we want to switch from Email to Text notifications, 
	// we have to locate and change code in multiple places:

	// somewhere is our application:
	TextNotification texter1; // changed from EmailNotification
	texter1.SendNotification("Person 1");

	// somewhere else is our application:
	TextNotification texter2; // changed from EmailNotification
	texter2.SendNotification("Person 2");

	system("pause");
	return 0;
}

