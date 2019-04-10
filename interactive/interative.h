#include <cstring>
#include <iostream>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

#define LOCALHOST   "127.0.0.1"

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

class server {
  Socket sock, cli;
  Address add, cliadd;
  int port;
  char buffer[1024];

public:
  server(int portno, string ip = LOCALHOST) : sock(newSocket()), port(portno) {
    add = setAddress(port, ip);
    sock = setSocket(sock, add, port);
    memset(buffer, 0, sizeof buffer);
  }
  void waitCon() {
    listen(sock, 5);
    socklen_t clilen = sizeof(cliadd);
    //cout << "waiting..." << endl;
    if ((cli = accept(sock, (sockaddr*)&cliadd, &clilen)) < 0) {
      error("waitCon/accept");
    }
    else {
      //cout << "Connected to " << getIP(cliadd) << endl;
    }
  }
  server& operator>>(string& s) {
  	read(cli, buffer, sizeof buffer);
		s = buffer;
    return *this;
  }
  server& operator<<(string& s) {
    send(cli, s.data(), s.length() + 1, 0);
    return *this;
  }
	~server() {
		if (sock) close(sock);
		if (cli)  close(cli);
	}
};
class client {
  Socket sock;
  int port;
  Address srvadd;
  char buffer[1024];

public:
  client(int portno, string ip = LOCALHOST) : port(portno) {
    sock = newSocket();
    srvadd = setAddress(port, ip);
  }
  void connection() {
    if (connect(sock, (sockaddr*)&srvadd, sizeof(srvadd)) < 0) {
      error("client connect");
    }
    else {
      //cout << "Connected to " << getIP(srvadd) << endl;
    }
  }
  client& operator>>(string& s) {
    read(sock, buffer, sizeof buffer);
		s = buffer;
    return *this;
  }
  client& operator<<(string& s) {
    send(sock, s.data(), s.length() + 1, 0);
    return *this;
  }
	~client() {
		if (sock) close(sock);
	}
};
