/*
Factory method defines an interface for creating a single object, 
but lets subclasses decide which class to instantiate. 
https://en.wikipedia.org/wiki/Factory_method_pattern
*/
#include <iostream>
#include <string>

using namespace std;

// in C++, interfaces are implemented using abstract classes
// where at least one of the functions is a pure virtual function

// Abstract base database;
// should define the inteface that is common and sufficiant for all the database types
class IDatabase {
public:
	virtual string GetDbConnectionString() = 0;
};

// Concrete database 1
class MsSqlDatabase : public IDatabase {
public:
	string GetDbConnectionString() {
		return "MS SQL";
	}
};

// Concrete database 2
class OracleDatabase : public IDatabase {
public:
	string GetDbConnectionString() {
		return "Oracle";
	}
};

// Abstract factory
// defines the method to create a database
class IDatabaseFactory {
public:
	virtual IDatabase* CreateDatabase() = 0;
};

// Concrete factory 1
// creates database 1
class MsSqlDatabaseFactory : public IDatabaseFactory {
public:
	IDatabase* CreateDatabase() {
		return new MsSqlDatabase;
	}
};

// Concrete factory 2
// creates database 2
class OracleDatabaseFactory : public IDatabaseFactory {
public:
	IDatabase* CreateDatabase() {
		return new OracleDatabase;
	}
};

enum DbType { MSSQL, Oracle };

int main()
{
	IDatabaseFactory* DbFactory;
	DbType type = MSSQL;
	// the switch statement is only needed once when creating the concrete factory
	switch (type)
	{
	case MSSQL: DbFactory = new MsSqlDatabaseFactory; break;
	case Oracle: DbFactory = new OracleDatabaseFactory; break;
	default: return -1;
	}
	IDatabase* Database = DbFactory->CreateDatabase();
	// we will work with the database through its abstract interface
	cout << Database->GetDbConnectionString() << endl;
	system("pause");
	return 0;
}
