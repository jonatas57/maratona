#include <iostream>
#include <cstring>

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

public:
  server(int portno, string ip = LOCALHOST) : sock(newSocket()), port(portno) {
    add = setAddress(port, ip);
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
	void operator<<(string& s) {
		send(sock, s.data(), s.length(), 0);
	}
	string receive() {
		char buffer[1024];
		recv(sock, buffer, 255, 0);
		send(sock, "", 0, 0);
		return buffer;
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

public:
  client(int portno, string ip = LOCALHOST) : port(portno) {
    sock = newSocket();
    srvadd = setAddress(portno, ip);
  }
  void connection() {
    if (connect(sock, (sockaddr*)&srvadd, sizeof(srvadd)) < 0) {
      error("client connect");
    }
    else {
      cout << "Connected to " << getIP(srvadd) << endl;
    }
  }
	void operator<<(string& s) {
		recv()
		send(sock, s.data(), s.length(), 0);
	}
	void operator>>(string& s) {
		char buffer[1024] = {0};
		recv(sock, buffer, 255, 0);
		s = buffer;
	}
	~client() {
		if (sock) close(sock);
	}
};
