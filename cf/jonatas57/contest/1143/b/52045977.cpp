#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int f(int n, int l, bool p = true) {
  if (l == 0) return n;
  int x = pow(10, l);
  int d = n / x, r = n % x, a = f(r, l - 1, false), b = f(x - 1, l - 1, false);
  bool aux = p && d == 1;
  return max(d * a, (aux ? b : (d - 1) * b));
}

int main() {
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int l = log10(n);
  cout << f(n, l) << endl;
  return 0;
}
