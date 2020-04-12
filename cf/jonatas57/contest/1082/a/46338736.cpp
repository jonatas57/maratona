#include <bits/stdc++.h>

using namespace std;

#define rep(a, b, c) for(int i = a;i < b;i++)
#define rp(a) rep(0, a, 1)
#define cr(x) cerr << "x = " << x << endl;
#define INF 1000000001

int calc(int n, int x, int y, int d) {
  int dist = abs(y - x);
  int z = dist / d;
  if (dist % d == 0) {
    return z;
  }
  else {
    if (y == 1 || y == n) {
      return z + 1;
    }
    else return INF;
  }
}

int mymin(int a, int b, int c) {
  int m = min(a, min(b, c));
  if (m == INF) {
    return -1;
  }
  else return m;
}

int main() {
  int t, n, x, y, d;
  cin >> t;
  rp(t) {
    cin >> n >> x >> y >> d;
    int xay  = calc(n, x, y, d);
    int xaum = calc(n, x, 1, d);
    int xan  = calc(n, x, n, d);
    int nay  = calc(n, n, y, d);
    int umay = calc(n, 1, y, d);
    int xumy = (xaum == -1 || umay == -1 ? -1 : xaum + umay);
    int xny = (xan == -1 || nay == -1 ? -1 : xan + nay);
    cout << mymin(xay, xumy, xny) << endl;
  }
}
