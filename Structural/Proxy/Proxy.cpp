/*
Proxy provides a surrogate or placeholder for another object to control access to it.
https://en.wikipedia.org/wiki/Proxy_pattern
*/

#include <iostream>
#include <string>
using namespace std;

// =============================================================================
// Type I: Virtual Proxy - The object we are proxying is expensive to create, 
// so we want to delay the instantiation until it is actually needed
// =============================================================================
class IAction {
public:
	virtual int getValue() = 0;
};

class RealObject : public IAction {
public:
	RealObject() {
		// some really expensive code here
	}
	virtual int getValue() {
		return 100;
	}
};

class ObjectProxy : public IAction {
private:
	IAction* object;
public:
	ObjectProxy() {
		object = NULL; // not instantiated just yet
	}
	virtual int getValue() {
		if (!object)
			object = new RealObject(); // this is the heavy part
		return object->getValue();
	}
};

// =============================================================================
// Type II: Protection Proxy - We want to limit access to the object we are proxying 
// =============================================================================

class IBank {
public:
	virtual int getAccountBallance() = 0;
	virtual void setAccountBallance(int ballance) = 0;
};

class ConcreteBank : public IBank {
private:
	int ballance;
public:
	ConcreteBank(int ballance) : ballance(ballance) {}
	virtual int getAccountBallance() { return ballance; }
	virtual void setAccountBallance(int _ballance) { ballance = _ballance; } // the method we don't want to be accessed by public
};

class ProxyBank : public IBank {
private:
	IBank* bank;
public:
	ProxyBank(int ballance) {
		bank = new ConcreteBank(ballance);
	}
	virtual int getAccountBallance() { return bank->getAccountBallance(); }
	virtual void setAccountBallance(int _ballance) { return; } // the real ballance is not changed
};

// =============================================================================
// Type III: Remote Proxy - a local representative to a remote object
// =============================================================================

// TODO; not implemented yet

int main() {
	// Type I: Virtual Proxy
	IAction* theObject = new ObjectProxy(); // we create ObjectProxy (cheap), not RealObject (expensive); maybe we will use it, maybe not
	cout << "*** Virtual Proxy ***" << endl;
	int someLogic = 68; // some randomness might occur here
	if (someLogic % 2 == 0)
		cout << theObject->getValue() << endl; // the expensive part happens here, but only if needed


	// Type II: Protection Proxy
	IBank* theBank = new ProxyBank(1000);
	cout << "*** Protection Proxy ***" << endl;
	cout << "Ballance: " << theBank->getAccountBallance() << endl; // the allowed operation
	theBank->setAccountBallance(1000000); // the not-allowed operation
	cout << "Ballance: " << theBank->getAccountBallance() << endl; // but no damage has actually happened

	system("pause");
	return 0;
}
