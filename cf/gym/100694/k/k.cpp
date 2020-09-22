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

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a), d(abs(b)) {
    if (b < 0) n = -n;
    ll m = gcd(abs(n), d);
    if (m) {
      n /= m;
      d /= m;
    }
  }
  bool operator<(const frac& f) const {
    return n * f.d < d * f.n;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  bool ans = true;
  int a, b, c, d;
  frac l(0), r(1);
  loop(n) {
    cin >> c >> d;
    if (c < d) swap(c, d);
    if (i) {
      int z = a - b - c + d;
      if (z) {
        frac f(d - b, z);
        if (z < 0) r = min(r, f);
        else l = max(l, f);
      }
      else if (b < d) ans = false;
    }
    a = c;
    b = d;
  }
  if (r < l) ans = false;
  cout << (ans ? "YES" : "NO") << endl;
  return 0;
}

