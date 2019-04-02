#include "interative.h"

using namespace std;

int main() {
  server srv(9000);
  srv.waitCon();
  cout << srv.receive() << endl;
  return 0;
}
