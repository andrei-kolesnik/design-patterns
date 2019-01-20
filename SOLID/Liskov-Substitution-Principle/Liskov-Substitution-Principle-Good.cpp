/*
Liskov's Substitution Principle
https://en.wikipedia.org/wiki/Liskov_substitution_principle
Derived classes must be substitutable for their base classes
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Good:
class Bird {
public:
	virtual void makeSound() = 0;
};

class FlyingBird : public Bird {
public:
	virtual void fly() { cout << "Flying!" << endl; }
};

class Duck : public FlyingBird {
public:
	virtual void makeSound() { cout << "Quack!" << endl; }
};

class Ostrich : public Bird {
public:
	virtual void makeSound() { cout << "Chirp!" << endl; }
};

int main() {
	vector<FlyingBird*> Flock;

	Flock.push_back(new Duck());
//	Flock.push_back(new Ostrich()); // won't compile

	for (auto bird : Flock)
	{
		bird->fly(); 
		bird->makeSound(); 
	}

	system("pause");
	return 0;
}