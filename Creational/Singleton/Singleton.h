#pragma once
class Singleton {
private:
	Singleton() { }
public:
	static int refCount;
	int prop; //setter and getter skipped for simplicity

	static Singleton* getInstance() {
		static Singleton instance;
		refCount++;
		return &instance;
	}
};
