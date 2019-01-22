/*
Interface segregation principle
https://en.wikipedia.org/wiki/Interface_segregation_principle
Many client-specific interfaces are better than one general-purpose interface
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Good:
class IFly {
public:
	virtual void fly() = 0;
};

class IMakeSound {
public:
	virtual void makeSound() = 0;
};

class Bird {
public: 
	string name;
	Bird(string name) : name(name) {}
};

class Duck : public Bird, public IFly, public IMakeSound {
public:
	Duck() : Bird("Duck") {}
	virtual void fly() { cout << name << ": Flying!" << endl; }
	virtual void makeSound() { cout << name << ": Quack!" << endl; }
};

class Ostrich : public Bird, public IMakeSound {
public:
	Ostrich() : Bird("Ostrich") {}
	virtual void makeSound() { cout << name << ": Chirp!" << endl; }
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
