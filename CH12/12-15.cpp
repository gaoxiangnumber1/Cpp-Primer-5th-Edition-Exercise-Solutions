#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_):ip(ip_), port(port_) { }
};
struct destination
{
	string ip;
	int port;
	destination(string ip_, int port_):ip(ip_), port(port_) { }
};

connection connect(destination* pDest)
{
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));
	cout << "creating connection(" << pConn.use_count() << ")\n";
	return *pConn;
}

void disconnect(connection pConn)
{
	cout << "connection close(" << pConn.ip << ":" << pConn.port << ")\n";
}

void f(destination &d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, [](connection *p)
	{
		disconnect(*p);
	});
	cout << "connecting now(" << p.use_count() << ")\n";
}

int main()
{
	destination dest("127.0.0.1", 7188);
	f(dest);
}
/*
Output:
creating connection(1)
connecting now(1)
connection close(127.0.0.1:7188)
*/
