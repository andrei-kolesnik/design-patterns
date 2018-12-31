/*
Command encapsulates a request as an object, thereby allowing for the parameterization of clients with different requests, and the queuing or logging of requests.
It also allows for the support of undoable operations.
https://en.wikipedia.org/wiki/Command_pattern
*/
#include <iostream>
#include <string>
using namespace std;

// Abstract command
class ICommand {
public:
	virtual void execute() = 0;
	virtual void unexecute() = 0;
};

// Concrete receiver
class TvReceiver {
private:
	bool isOn;
	int volume;
public:
	TvReceiver() : isOn(false), volume(5) {}
	void actionOn() {
		if (!isOn)
		{
			isOn = true;
			cout << "TV is on" << endl;
		}
	}
	void actionOff() {
		if (isOn)
		{
			isOn = false;
			cout << "TV is off" << endl;
		}
	}
	void actionUp() {
		cout << "TV volume is " << ++volume << endl;
	}
	void actionDown() {
		if (volume > 0)
			cout << "TV volume is " << --volume << endl;
	}
};

// Concrete commands
class OnCommand : public ICommand {
private:
	TvReceiver receiver;
public:
	OnCommand(TvReceiver receiver) : receiver(receiver) {}
	virtual void execute() { receiver.actionOn(); }
	virtual void unexecute() { receiver.actionOff(); }
};

class OffCommand : public ICommand {
private:
	TvReceiver receiver;
public:
	OffCommand(TvReceiver receiver) : receiver(receiver) {}
	virtual void execute() { receiver.actionOff(); }
	virtual void unexecute() { receiver.actionOn(); }
};

class UpCommand : public ICommand {
private:
	TvReceiver receiver;
public:
	UpCommand(TvReceiver receiver) : receiver(receiver) {}
	virtual void execute() { receiver.actionUp(); }
	virtual void unexecute() { receiver.actionDown(); }
};

class DownCommand : public ICommand {
private:
	TvReceiver receiver;
public:
	DownCommand(TvReceiver receiver) : receiver(receiver) {}
	virtual void execute() { receiver.actionDown(); }
	virtual void unexecute() { receiver.actionUp(); }
};

class Invoker {
private:
	ICommand* on;
	ICommand* off;
	ICommand* up;
	ICommand* down;
public:
	Invoker(ICommand* on, ICommand* off, ICommand* up, ICommand* down) :
		on(on), off(off), up(up), down(down) {}
	void actionOn() {
		on->execute();
		for (int i = 0; i < 5; i++)
			up->execute();
	}
	void actionOff() {
		for (int i = 0; i < 5; i++)
			up->unexecute();
		on->unexecute();
	}
};

int main() {
	TvReceiver tv;
	Invoker remote(new OnCommand(tv), new OffCommand(tv), new UpCommand(tv), new DownCommand(tv));
	remote.actionOn();
	remote.actionOff();
	system("pause");
}