#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int a, b;
    cin >> a >> b;
    vi as, bs;
    for (int i = a % 10, base = 1;a;base *= 10, i = a % 10) {
      if (i) as.push_back(i * base);
      a /= 10;
    }
    for (int i = b % 10, base = 1;b;base *= 10, i = b % 10) {
      if (i) bs.push_back(i * base);
      b /= 10;
    }
    bool ok = false;
    each(x, as) each(y, bs) {
      if (ok) cout << " + ";
      cout << x << " x " << y;
      ok = true;
    }
    cout << endl;
  }
  return 0;
}

