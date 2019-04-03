#include "interative.h"

using namespace std;

int main() {
  client cli(9000);
  cli.connection();
  cli.sendmsg("Hello server!!");
  cout << cli.receive() << endl;
  return 0;
}
