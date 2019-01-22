/*
Interface segregation principle
https://en.wikipedia.org/wiki/Interface_segregation_principle
Many client-specific interfaces are better than one general-purpose interface
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// Bad:
class IBird {
public:
	virtual void fly() = 0;
	virtual void makeSound() = 0;
};

class Duck : public IBird {
public:
	virtual void fly() { cout << "Flying!" << endl; }
	virtual void makeSound() { cout << "Quack!" << endl; }
};

class Ostrich : public IBird {
public:
	virtual void fly() { throw exception("Cant's fly!"); } // Ostrich does not need the "fly" method and should not have to implement it
	virtual void makeSound() { cout << "Chirp!" << endl; }
};

int main() {
	vector<IBird*> Flock;

	Flock.push_back(new Duck());
	Flock.push_back(new Ostrich());

	for (auto bird : Flock)
	{
		bird->fly();
		bird->makeSound(); // there be exceptions!
	}

	system("pause");
	return 0;
}

