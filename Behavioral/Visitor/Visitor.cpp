/*
Visitor lets a new operation be defined without changing the classes of the elements on which it operates.
Visitor separates an algorithm from an object structure by moving the hierarchy of methods into one object.
https://en.wikipedia.org/wiki/Visitor_pattern
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class IVisitor; // Forward declaration of the abstract Visitor

// Abstract Visitable: parent class for applications
class IVisitable {
protected:
	int price;
	string name;
public:
	int getPrice() {
		return price;
	}
	string getName() {
		return name;
	}
	void display() {
		cout << name << ": price is " << price << endl;
	}
	// Accepts any IVisitor
	virtual void accept(IVisitor&) = 0;
};

// Forward declarations of the concrete applications
class FreeApplication;
class ProApplication;
class EnterpriseApplication;

// Abstract Visitor: parent class for offers
class IVisitor {
protected:
	string name;
public:
	void display(string appName, int appPrice) {
		cout << name << ": " << appName << " price is " << appPrice << endl;
	}
	// Overloads for all kinds of IVisitable
	virtual void visit(FreeApplication&) = 0;
	virtual void visit(ProApplication&) = 0;
	virtual void visit(EnterpriseApplication&) = 0;
};

// Concrete Visitable #1	
class FreeApplication : public IVisitable {
public:
	FreeApplication() {
		price = 0;
		name = "Free App";
	}
	void accept(IVisitor& visitor) {
		visitor.visit(*this);
	}
};

// Concrete Visitable #2
class ProApplication : public IVisitable {
public:
	ProApplication() {
		price = 20;
		name = "Pro App";
	}
	void accept(IVisitor& visitor) {
		visitor.visit(*this);
	}
};

// Concrete Visitable #3	
class EnterpriseApplication : public IVisitable {
public:
	EnterpriseApplication() {
		price = 100;
		name = "Enterprise App";
	}
	void accept(IVisitor& visitor) {
		visitor.visit(*this);
	}
};

// Concrete Visitor #1
class SignupOffer : public IVisitor {
public:
	SignupOffer() {
		name = "Signup Offer";
	}
	void visit(FreeApplication& app) {
		display(app.getName(), app.getPrice());
	}
	void visit(ProApplication& app) {		
		display(app.getName(), app.getPrice() - 2);
	}
	void visit(EnterpriseApplication& app) {
		display(app.getName(), app.getPrice() / 10 * 8);
	}
};

// Concrete Visitor #2
class SaleOffer : public IVisitor {
public:
	SaleOffer() {
		name = "Holiday Sale";
	}
	void visit(FreeApplication& app) {
		display(app.getName(), app.getPrice());
	}
	void visit(ProApplication& app) {
		display(app.getName(), app.getPrice() - 5);
	}
	void visit(EnterpriseApplication& app) {
		display(app.getName(), app.getPrice() / 2);
	}
};

int main() {
	FreeApplication freeApp;
	ProApplication proApp;
	EnterpriseApplication entApp;

	SignupOffer signup;
	SaleOffer sale;

	freeApp.display();
	proApp.display();
	entApp.display();

	freeApp.accept(signup);
	proApp.accept(signup);
	entApp.accept(signup);

	freeApp.accept(sale);
	proApp.accept(sale);
	entApp.accept(sale);

	getchar();
}