/*
Singleton pattern restricts object creation for a class to only one instance.
https://en.wikipedia.org/wiki/Singleton_pattern
*/
#include <iostream>
#include "Singleton.h"

using namespace std;

int Singleton::refCount = 0;

int main()
{
	// Singleton* s1 = new Singleton(); //won't compile - Singleton constructor is private
	Singleton* s1 = Singleton::getInstance();
	s1->prop = 100;
	cout << "After s1: reference count: " << s1->refCount << " s1 property: " << s1->prop << endl;

	Singleton* s2 = Singleton::getInstance();
	cout << "After s2: reference count: " << s2->refCount << " s2 property: " << s2->prop << endl;

	s2->prop = 200;
	cout << "s1 property: " << s1->prop << endl;
	cout << "s2 property: " << s2->prop << endl;

	system("pause");
	return 0;
}
