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
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
  friend istream& operator<<(istream& is, point& p) {
    int x, y;
    is >> x >> y;
    p = point(x, y);
    return is;
  }
};

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a), d(abs(b)) {
    if (b < 0) n = -n;
    ll m = __gcd(abs(n), d);
    if (m) {
      n /= m;
      d /= m;
    }
  }
  bool operator<(const frac& f) const {
    return n * f.d < d * f.n;
  }
};

ll normsq(point p) {
  return p.x * p.x + p.y * p.y;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  for (int t = 1;cin >> n and n;t++) {
    map<pair<frac, int>, vector<pair<point, int>>> ps;
    loop(n) {
      int x, y, z;
      cin >> x >> y >> z;
      ps[make_pair(frac(y, x), y < 0 or (y == 0 and x < 0))].emplace_back(point(x, y), z);
    }
    vector<point> ans;
    each(kv, ps) {
      sort(iter(kv.second), [](pair<point, int> a, pair<point, int> b) {
        return normsq(a.first) < normsq(b.first);
      });
      int h = -1;
      each(ph, kv.second) {
        if (ph.second > h) {
          h = ph.second;
        }
        else ans.push_back(ph.first);
      }
    }
    cout << "Data set " << t << ":" << endl;
    if (ans.empty()) {
      cout << "All the lights are visible." << endl;
    }
    else {
      cout << "Some lights are not visible:" << endl;
      sort(iter(ans));
      int l = ans.size();
      loop(l) {
        cout << "x = " << ans[i].x << ", y = " << ans[i].y << (i == l - 1 ? "." : ";") << endl;
      }
    }
  }
  return 0;
}

