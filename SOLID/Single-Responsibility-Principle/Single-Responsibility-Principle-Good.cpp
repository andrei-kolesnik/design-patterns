/*
Single Responsibility Principle
https://en.wikipedia.org/wiki/Single_responsibility_principle
A class should have only a single responsibility (reason to change)
*/
#include <iostream>
#include <string>
using namespace std;

class EmailValidationService {
public:
	void Validate(string email) {
		if (email.find("@") == string::npos || email.find(".") == string::npos)
			throw exception("Not valid email");
	}
};

class EmailService {
private:
	EmailValidationService emailvalidator;
public:
	void SendEmail(string email, string name, string subject)
	{
		emailvalidator.Validate(email);
		cout << "From: user@test.com"
			<< "To: " << name << "<" << email << ">"
			<< subject << endl;
	}
};

int main() {
	EmailService email;
	email.SendEmail("user.gmail.com", "Some User", "Welcome to the newsletter");

	system("pause");
	return 0;
}