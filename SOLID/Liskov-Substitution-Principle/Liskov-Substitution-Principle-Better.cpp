/*
Liskov's Substitution Principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle
Derived classes must be substitutable for their base classes
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Better:
class IFly {
public:
	virtual void fly() = 0;
};

class IMakeSound {
public:
	virtual void makeSound() = 0;
};

class Bird {
};

class Duck : public Bird, public IFly, public IMakeSound {
public:
	virtual void fly() { cout << "Flying!" << endl; }
	virtual void makeSound() { cout << "Quack!" << endl; }
};

class Ostrich : public Bird, public IMakeSound {
public:
	virtual void makeSound() { cout << "Chirp!" << endl; }
};

int main() {
	vector<IFly*> FlyingFlock;
	vector<IMakeSound*> NoicyFlock;

	FlyingFlock.push_back(new Duck());

	NoicyFlock.push_back(new Duck());
	NoicyFlock.push_back(new Ostrich());

	for (auto bird : FlyingFlock)
		bird->fly();

	for (auto bird : NoicyFlock)
		bird->makeSound();

	system("pause");
	return 0;
}
