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

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
};

ll dist(point& p, point& q) {
  point del = p - q;
  return del.x * del.x + del.y * del.y;
}

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a), d(b) {
    if (d < 0) d = -d, n = -n;
    ll m = gcd(abs(n), abs(d));
    n /= m;
    d /= m;
    if (d == 0) n = -1;
  }
  frac(point p) : frac(p.y, p.x) {}
  bool operator<(const frac& f) const {
    return n * f.d < f.n * d;
  }
};

ll choose(ll x) {
  return x * (x - 1) / 2;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  vector<point> ps;
  cin >> n;
  loop(n) {
    int x, y;
    cin >> x >> y;
    ps.emplace_back(x, y);
  }
  map<pair<frac, ll>, ll> cnt;
  loop(n) {
    for (int j = i + 1;j < n;j++) {
      cnt[make_pair(frac(ps[i] - ps[j]), dist(ps[i], ps[j]))]++;
    }
  }
  ll ans = 0;
  for (auto& [f, q] : cnt) {
    ans += choose(q);
  }
  cout << ans / 2 << endl;
  return 0; 
}

