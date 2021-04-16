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
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
};

istream& operator>>(istream& is, point& p) {
  is >> p.x >> p.y;
  return is;
}

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a), d(b) {
    if (b < 0) n = -n, d = -d;
    ll m = gcd(abs(n), d);
    if (m) {
      n /= m;
      d /= m;
    }
    if (n == 1 and !d) n = -1;
  }
  bool operator<(const frac& f) const {
    return n * f.d < d * f.n;
  }
  bool operator==(const frac& f) const {
    return n == f.n and d == f.d;
  }
  frac perp() const {
    return frac(-d, n);
  }
};

struct line {
  ll a, b, c;
  point p, q;
  frac ang;
  line(point p, point q) : p(p), q(q) {
    point del = p - q;
    ang = frac(del.y, del.x);
    a = ang.n;
    b = -ang.d;
    c = -(a * p.x + b * p.y);
  }
  bool operator<(const line& l) const {
    return ang == l.ang ? c < l.c : ang < l.ang;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    point a, b;
    map<frac, set<line>> lines;
    loop(n) {
      cin >> a >> b;
      line l(a, b);
      lines[l.ang].insert(l);
    }
    ll ans = 0;
    for (auto& [f, ls] : lines) {
      ans += (ll)ls.size() * (ll)lines[f.perp()].size();
    }
    cout << ans / 2 << endl;
  }
  return 0;
}

