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

class INotify {
public:
	virtual void SendNotification(string name) = 0;
};

class EmailNotification : public INotify {
public:
	void SendNotification(string name) {
		cout << "Email Notification sent to " << name << endl;
	}
};

class TextNotification : public INotify {
public:
	void SendNotification(string name) {
		cout << "Text Notification sent to " << name << endl;
	}
};

class NotifierFactory {
public:
	INotify* CreateNotifier() {
		//return new EmailNotification(); // this is the only place we need to change
		return new TextNotification();
	}
};

int main() {
	NotifierFactory factory;

	// somewhere is our application:
	factory.CreateNotifier()->SendNotification("Person 1");

	// somewhere else is our application:
	factory.CreateNotifier()->SendNotification("Person 2");

	// Now if we want to switch from Email to Text notifications, we only need to change NotifierFactory,
	// no other changes needed:

	// somewhere is our application:
	factory.CreateNotifier()->SendNotification("Person 1");

	// somewhere else is our application:
	factory.CreateNotifier()->SendNotification("Person 2");

	system("pause");
	return 0;
}
