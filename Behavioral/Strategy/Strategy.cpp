/*
Strategy defines a family of algorithms, encapsulate each one, and make them interchangeable. 
Strategy lets the algorithm vary independently from clients that use it, 
changing inheritance (is-a) to composition (has-a).
https://en.wikipedia.org/wiki/Strategy_pattern
*/

#include <iostream>
#include <string>
using namespace std;

//Abstract payment behaviour
class IPayment {
public:
	virtual void pay() = 0;
};

//Concrete payment behaviours
class VisaPayment : public IPayment {
public:
	virtual void pay() {
		cout << "paid by Visa" << endl;
	}
};

class CashPayment : public IPayment {
public:
	virtual void pay() {
		cout << "paid by cash" << endl;
	}
};

//Abstract shipping behaviour
class IShipping {
public:
	virtual void ship() = 0;
};

//Concrete shipping behaviours
class UpsShipping : public IShipping {
	virtual void ship() {
		cout << "ship by UPS" << endl;
	}
};

class FedexShipping : public IShipping {
	virtual void ship() {
		cout << "ship by Fedex" << endl;
	}
};

class Purchase {
private:
	IPayment* payment;
	IShipping* shipping;
	string item;
public:
	Purchase(string item, IPayment* payment, IShipping* shipping) : 
		item(item), payment(payment), shipping(shipping) {}
	void pay() { payment->pay(); }
	void ship() { shipping->ship(); }
	void get() {
		cout << item << endl;
		pay();
		ship();
	}
};

int main()
{
	Purchase p1("Computer", new VisaPayment, new UpsShipping);
	p1.get();
	Purchase p2("Printer", new VisaPayment, new FedexShipping);
	p2.get();
	Purchase p3("Scanner", new CashPayment, new UpsShipping);
	p3.get();
	Purchase p4("Headphones", new CashPayment, new FedexShipping);
	p4.get();
	system("pause");
	return 0;
}
