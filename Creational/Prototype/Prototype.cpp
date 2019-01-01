/*
Prorotype specifies the kinds of objects to create using a prototypical instance, 
and create new objects from the 'skeleton' of an existing object, 
thus boosting performance and keeping memory footprints to a minimum.
https://en.wikipedia.org/wiki/Prototype_pattern
*/
#include <iostream>
#include <string>
using namespace std;

// Abstract prototype
class IPrototype {
public:
	virtual IPrototype* clone() = 0;
	virtual int getState() = 0;
	virtual void setState(int state) = 0;
};

// Concrete prototype
class RealPrototype : public IPrototype {
private:
	// copy constructor is hidden from the public
	RealPrototype(const RealPrototype& other) : state(other.state) {
		// do class-spesific property copying here
	} 
	int state;
public:
	RealPrototype(int state) : state(state) {}
	virtual IPrototype* clone() { return new RealPrototype(*this); }
	virtual int getState() { return state; }
	virtual void setState(int _state) { state = _state; }
};

int main() {
	IPrototype* original = new RealPrototype(100);
	IPrototype* copy = original->clone();
	cout << "Original: " << original->getState() << endl;
	cout << "Copy: " << copy->getState() << endl;
	copy->setState(200);
	cout << "Original: " << original->getState() << endl;
	cout << "Copy: " << copy->getState() << endl;
	system("pause");
}
