/*
Liskov's Substitution Principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle
Derived classes must be substitutable for their base classes
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Bad:
class Bird {
public:
	virtual void fly() { cout << "Flying!" << endl; }
	virtual void makeSound() = 0;
};

class Duck : public Bird {
public:
	virtual void makeSound() { cout << "Quack!" << endl; }
};

class Ostrich : public Bird {
public:
	virtual void fly() { throw exception("Can't fly!"); }
	virtual void makeSound() { cout << "Chirp!" << endl; }
};

int main() {
	vector<Bird*> Flock;

	Flock.push_back(new Duck());
	Flock.push_back(new Ostrich());

	for (auto bird : Flock)
	{
		bird->fly(); // there be exceptions!
		bird->makeSound(); 
	}

	system("pause");
	return 0;
}