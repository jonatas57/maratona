#include "interative.h"

using namespace std;

int main() {
  client cli(9000);
  cli.connection();
  string s;
  cin >> s;
  cli << s;
  return 0;
}
