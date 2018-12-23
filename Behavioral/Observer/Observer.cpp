/*
Observer define a one-to-many dependency between objects 
where a state change in one object results in all its dependents 
being notified and updated automatically, changing from "pull" to "push" behaviour.
https://en.wikipedia.org/wiki/Observer_pattern
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract observer / subscriber
class IObserver {
public:
	virtual void Update() = 0;
};

// Abstract observable publisher
class ISubject {
public:
	virtual void Register(IObserver* newObserver) = 0;
	virtual void UnRegister(IObserver* deleteObserver) = 0;
	virtual void Notify() = 0;
};

// Concrete subject
class Subject : public ISubject {
private:
	vector<IObserver*> observers;
public:
	virtual void Register(IObserver* newObserver) {
		observers.push_back(newObserver);
	}

	virtual void UnRegister(IObserver* deleteObserver) {
		observers.erase(find(observers.begin(), observers.end(), deleteObserver));
	}

	virtual void Notify() {
		for (auto observer : observers)
			observer->Update();
	}
};

// Concrete observer
class Observer : public IObserver {
private:
	ISubject* subject;
public:
	Observer(ISubject* _subject) : subject(_subject) {
		subject->Register(this);
	}

	~Observer() {
		subject->UnRegister(this);
	}

	void Update() {
		cout << "Change happened" << endl;
	}
};

int main() {
	Subject subject;
	Observer observer1(&subject), observer2(&subject);
	subject.Notify();
	getchar();
}