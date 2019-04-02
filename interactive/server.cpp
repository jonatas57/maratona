#include "interative.h"

using namespace std;

int main() {
  server srv(9000);
  srv.waitCon();
  return 0;
}
