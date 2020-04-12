#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0;i < n;i++) {
    cin >> h[i];
  }
  vector<bool> dis(n, false);
  for (int i = 1;i < n - 1;i++) {
    dis[i] = h[i - 1] && !h[i] && h[i + 1];
  }
  for (int i = 1;i < n - 1;i++) {
    cerr << dis[i];
  }
  cerr << endl;
  int d = 0;
  for (int i = 1;i < n - 1;i++) {
    if (dis[i]) {
      d++;
      if (dis[i + 2]) dis[i + 2] = false;
    }
  }
  cout << d << endl;
  return 0;
}
