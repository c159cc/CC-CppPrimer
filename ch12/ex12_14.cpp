#include "../common/cc.h"

struct connection
{
    string ip;
    int port;
    connection(string ip, int port) : ip(ip), port(port) {};
};

struct destination
{
    string ip;
    int port;
    destination(string ip, int port) : ip(ip), port(port) {};
};

connection connect(destination *d)
{
    // return connection(d->ip, d->port);
    shared_ptr<connection> p(new connection(d->ip, d->port));
    return *p;
}

void disconnect(connection *c)
{
}

void f(destination *d)
{
    connection c = connect(d);
    shared_ptr<connection> p(&c, [](connection *){ cout << "Connection released" << endl; });
    cout << "Connection: " << p->ip << ":" << p->port << endl;
}
int main()
{
    destination d("192.168.1.2", 80);
    f(&d);
    cout << "main function ends" << endl;
    return 0;
}