/*
Adapter (or Wrapper, or Translator) converts the interface of a class into another interface clients expect.
An adapter lets classes work together that could not otherwise because of incompatible interfaces. 
The enterprise integration pattern equivalent is the translator.
https://en.wikipedia.org/wiki/Adapter_pattern
*/

#include <iostream>
#include <string>
using namespace std;

class IWeHave {
public:
	virtual void requestWeHave(string s, int num) = 0;
};

class IWeWant {
public:
	virtual void requestWeWant(int num, string s) = 0; // different signature
};

class Server : public IWeWant {
public:
	virtual void requestWeWant(int num, string s) {
		for (int i = 0; i < num; i++)
			cout << s;
		cout << endl;
	}
};

class Adapter : public IWeHave {
	IWeWant* server;
public:
	Adapter(IWeWant* server) : server(server) {}
	virtual void requestWeHave(string s, int num) {
		server->requestWeWant(num, s); // calling the wanted method with the different signature
	}
};

int main() 
{ // this is our client part
	Server server;
	Adapter adapter(&server);
	adapter.requestWeHave("a", 4);
	system("pause");
	return 0;
}
