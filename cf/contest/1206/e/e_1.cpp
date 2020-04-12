#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define keach(k, v, s)     for(auto& [k, v] : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define cc(x)              cerr << #x << " = " << x << endl;

bool ask(int a, int b, int c, int d) {
  cout << "? " << a << " " << b << " " << c << " " << d << endl;
  cout.flush();
  int x;
  cin >> x;
  return x == 1;
}

int main() {
  int n;
  cin >> n;
  vector<vi> a(n, vi(n, -1));
  a[0][0] = 1;
  a[n - 1][n - 1] = 0;
  loop(n) {
    vloop(j, n) {
      if (i + j >= 2 && (i != n - 1 || j != n - 1)) {
        a[i][j] = ask(1, 1, i + 1, j + 1);
      }
    }
  }
  a[0][1] = !ask(1, 2, n, n);
  a[1][0] = !ask(2, 1, n, n);
  cout << "!\n";
  each(x, a) {
    each(y, x) {
      cout << y;
    }
    cout << endl;
  }
  cout.flush();
	return 0;
}
