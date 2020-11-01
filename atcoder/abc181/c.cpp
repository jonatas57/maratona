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

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator^(const point& p) const {
    return x * p.y - y * p.x;
  }
  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vector<point> ps(n);
  loop(n) cin >> ps[i];
  bool ok = false;
  for (int i = 0;i < n and !ok;i++) {
    for (int j = i + 1;j < n and !ok;j++) {
      point p = ps[j] - ps[i];
      for (int k = j + 1;k < n and !ok;k++) {
        if (p ^ (ps[k] - ps[i])) continue;
        ok = true;
      }
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

