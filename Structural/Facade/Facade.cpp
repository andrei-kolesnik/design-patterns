/*
Facade provides a unified interface to a set of interfaces in a subsystem.
Facade defines a higher-level interface that makes the subsystem easier to use.
https://en.wikipedia.org/wiki/Facade_pattern
*/

#include <iostream>
#include <string>
using namespace std;

// complex stuff we want to hide
class SqlConnection {
private:
	string connection;
public:
	SqlConnection(string connection) : connection(connection) {}
};

class SqlServer {
private:
	string name;
	SqlConnection* connection;
public:
	SqlServer(string name) : name(name) {}
	void Connect(SqlConnection* conn) { connection = conn; }
	void Execute(string query) { cout << query << " [executed on " << name << "]" << endl;  }
};

class SqlCommand {
private:
	SqlServer* server;
	string query;
public:
	SqlCommand(SqlServer* server) : server(server) {}
	void Execute(string query) { server->Execute(query); }
};

// simple interface we want to deal with
class SqlFacade {
public:
	void DoSql(string server, string query) {
		// this is where we hide all the complexity, so the client only need to make simplified requests
		SqlConnection* conn = new SqlConnection("SERV=" + server);
		SqlServer* serv = new SqlServer(server);
		serv->Connect(conn);
		SqlCommand* comm = new SqlCommand(serv);
		comm->Execute(query);
	}
};

int main()
{ 
	SqlFacade myServer;
	myServer.DoSql("SERVER1", "UPDATE customer SET active = 1 WHERE id = 42");

/* instead of:
	SqlConnection* conn = new SqlConnection("SERV=SERVER1");
	SqlServer* serv = new SqlServer("SERVER1");
	serv->Connect(conn);
	SqlCommand* comm = new SqlCommand(serv);
	comm->Execute(query);
*/
	system("pause");
	return 0;
}
