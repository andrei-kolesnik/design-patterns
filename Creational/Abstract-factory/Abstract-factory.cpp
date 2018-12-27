/*
Abstract Factory provides an interface for creating families of related or dependent objects 
without specifying their concrete classes.
https://en.wikipedia.org/wiki/Abstract_factory_pattern
*/
#include <iostream>
#include <string>

using namespace std;

// in C++, interfaces are implemented using abstract classes
// where at least one of the functions is a pure virtual function

// Abstract base database;
// should define the inteface that is common and sufficiant for all the database types
class IBrand {
public:
	virtual int getPrice() = 0;
	virtual string getMateruial() = 0;
};

// Concrete brand 1
class GucciBrand : public IBrand {
public:
	virtual int getPrice() { return 1000; }
	virtual string getMateruial() { return "Crocodile skin"; }
};

// Concrete brand 2
class PucciBrand : public IBrand {
public:
	virtual int getPrice() { 
		GucciBrand gucci;
		return gucci.getPrice() / 3;
	}
	virtual string getMateruial() { return "Plastic"; }
};

// Abstract product 1
class IBag {
	virtual string getMaterial() = 0;
};

// Abstract product 2
class IShoes {
	virtual int getPrice() = 0;
};

// Concrete product 1
class Bag : public IBag {
private:
	IBrand* brand;
public:
	Bag(IBrand* _brand) : brand(_brand) {}
	virtual string getMaterial() { return brand->getMateruial(); }
};

// Concrete product 2
class Shoes : public IShoes {
private:
	IBrand* brand;
public:
	Shoes(IBrand* _brand) : brand(_brand) {}
	virtual int getPrice() { return brand->getPrice(); }
};

// Abstract factory
// defines the method to create abstract products
class IBrandFactory {
public:
	virtual IBag* CreateBag() = 0;
	virtual IShoes* CreateShoes() = 0;
};

// Concrete factory 1
// creates brand 1 products
class GucciFactory : public IBrandFactory {
public:
	virtual IBag* CreateBag() { return new Bag(new GucciBrand); }
	virtual IShoes* CreateShoes() { return new Shoes(new GucciBrand); }
};

// Concrete factory 2
// creates brand 2 products
class PucciFactory : public IBrandFactory {
public:
	virtual IBag* CreateBag() { return new Bag(new PucciBrand); }
	virtual IShoes* CreateShoes() { return new Shoes(new PucciBrand); }
};

class Shop {
public:
	string name;
	Bag* bag;
	Shoes* shoes;
	Shop(string _name, IBrandFactory* factory) : name(_name) {
		bag = (Bag*)factory->CreateBag();
		shoes = (Shoes*)factory->CreateShoes();
	}
};

int main()
{
	bool IAmRich = false;
	Shop* shop;

	if (IAmRich)
		shop = new Shop("Macy's", new GucciFactory);
	else
		shop = new Shop("Street market", new PucciFactory);

	cout << "At " << shop->name << ", I bought a " << shop->bag->getMaterial() << " bag and some shoes for $" << shop->shoes->getPrice() << endl;

	system("pause");
	return 0;
}
