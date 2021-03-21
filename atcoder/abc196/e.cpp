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

  int n;
  cin >> n;
  vector<ll> a(n), t(n);
  ll l = -1000000000, r = -l, del = 0;
  loop(n) {
    cin >> a[i] >> t[i];
    if (t[i] == 1) {
      del += a[i];
      l += a[i];
      r += a[i];
    }
    else if (t[i] == 2) {
      l = max(l, a[i]);
      if (l > r) r = l;
    }
    else {
      r = min(r, a[i]);
      if (r < l) l = r;
    }
  }
  ll q, x;
  cin >> q;
  loop(q) {
    cin >> x;
    x += del;
    cout << min(r, max(l, x)) << endl;
  }
  return 0;
}

