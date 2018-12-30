/*
Decorator attaches additional responsibilities to an object dynamically keeping the same interface. 
Decorators provide a flexible alternative to subclassing for extending functionality.
https://en.wikipedia.org/wiki/Decorator_pattern
*/
#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// Abstract component
class IComponent {
public:
	virtual string getMessage() = 0;
};

// Concrete component
#pragma warning(disable : 4996) // to suppress "depreciated" messages
class BaseComponent : public IComponent {
public:
	virtual string getMessage() override {
		OSVERSIONINFOEX info;
		ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
		info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
		GetVersionEx((LPOSVERSIONINFO)&info);
		stringstream ss;
		ss << "Windows version: " << 
			info.dwMajorVersion << "." << 
			info.dwMinorVersion << " (" << 
			info.dwBuildNumber << ")";
		return ss.str();
	}
};

// Abstract decorator
class BaseDecorator : public IComponent {
public:
	IComponent* component{ nullptr };
	BaseDecorator(IComponent* _component) : component(_component) {}
	virtual string getMessage() { return component->getMessage(); }
};

// Concrete decorator 1
class UpperCaseDecorator : public BaseDecorator {
public:
	UpperCaseDecorator(IComponent* _component) : BaseDecorator(_component) {}
	virtual string getMessage() override {
		string message = component->getMessage();
		transform(message.begin(), message.end(), message.begin(), toupper);
		return message;
	}
};

char leetcode(char c)
{
	switch (c) {
	case 'o': case 'O': return '0';
	case 'i': case 'I': return '1';
	default: return c;
	}
}

// Concrete decorator 2
class LeetCodeDecorator : public BaseDecorator {
public:
	LeetCodeDecorator(IComponent* _component) : BaseDecorator(_component) {}
	virtual string getMessage() override {
		string message = component->getMessage();
		transform(message.begin(), message.end(), message.begin(), leetcode);
		return message;
	}
};

int main() {
	BaseComponent comp1;
	cout << comp1.getMessage() << endl;

	UpperCaseDecorator comp2(new BaseComponent); 
	cout << comp2.getMessage() << endl;

	LeetCodeDecorator comp3(new BaseComponent);
	cout << comp3.getMessage() << endl;

	LeetCodeDecorator comp4(new UpperCaseDecorator(new BaseComponent));
	cout << comp4.getMessage() << endl;

	getchar();
}
