#include <iostream>
#include <cstring>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

using namespace std;

typedef int         Socket;
typedef sockaddr_in Address;

void error(string s) {
  perror(s.data());
  exit(1);
}
Socket newSocket() {
  Socket s;
  if ((s = socket(AF_INET, SOCK_STREAM, 0)) != -1) {
    return s;
  }
  else {
    error("New socket error");
  }
  return -1;
}
Address setAddress(int port) {
  Address serv;
  memset(&serv, 0, sizeof serv);
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv.sin_port = htons(port);
  return serv;
}
Address setAddress(int port, string ip) {
  Address serv;
  memset(&serv, 0, sizeof serv);
  serv.sin_family = AF_INET;
  serv.sin_addr.s_addr = inet_addr(ip.data());
  serv.sin_port = htons(port);
  return serv;
}
Socket setSocket(Socket s, Address address, int port) {
  if (bind(s, (sockaddr*)&address, sizeof(address)) < 0) {
    error("setSocket/bind");
  }
  return s;
}
string getIP(Address& add) {
  return inet_ntoa(add.sin_addr);
}

struct server {
  Socket sock, cli;
  Address add, cliadd;
  int port;

  server(int portno) : sock(newSocket()), port(portno) {
    add = setAddress(port);
    sock = setSocket(sock, add, port);
  }
  void waitCon() {
    listen(sock, 5);
    socklen_t clilen = sizeof(cliadd);
    cout << "waiting..." << endl;
    if ((cli = accept(sock, (sockaddr*)&cliadd, &clilen)) < 0) {
      error("waitCon/accept");
    }
    else {
      cout << "Connected to " << getIP(cliadd) << endl;
    }
  }
};
struct client {
  Socket sock;
  int port;
  Address srvadd;

  client(int portno) : port(portno) {
    sock = newSocket();
    srvadd = setAddress(portno);
  }
  void connection() {
    if (connect(sock, (sockaddr*)&srvadd, sizeof(srvadd)) < 0) {
      error("client connect");
    }
    else {
      cout << "Connected to " << getIP(srvadd) << endl;
    }
  }
};
