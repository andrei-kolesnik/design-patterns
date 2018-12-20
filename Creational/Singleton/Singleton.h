#pragma once
class Singleton {
private:
	Singleton() { } // Singleton constructor is private so it cannot be instantiated directly
public:
	static int refCount;
	int prop; //setter and getter skipped for simplicity

	static Singleton* getInstance() {
		static Singleton instance;
		refCount++;
		return &instance;
	}
};
