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
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  point operator*(const ll a) const {
    return point(a * x, a * y);
  }
  void operator/=(const ll a) {
    x /= a;
    y /= a;
  }
  ll operator^(const point& p) const {
    return x * p.y - y * p.x;
  }

  bool operator<(const point& p) const {
    return x == p.x ? x < p.x : y < p.y;
  }
  bool operator==(const point& p) const {
    return x == p.x and y == p.y;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

void convex(vector<point>& ps) {
  ll val = (ps[1] - ps[0]) ^ (ps[2] - ps[1]);
  for (int i = 2;i <= 4;i++) {
    if ((((ps[i - 1] - ps[i - 2]) ^ (ps[i] - ps[i - 1])) < 0) xor (val < 0)) {
      swap(ps[i], ps[i - 1]);
      if (i == 4) ps[0] = ps[4];
      break;
    }
  }
}

bool isparallel(point& a, point& b, point& c, point& d) {
  point del1 = b - a, del2 = d - c;
  del1 /= __gcd(abs(del1.x), abs(del1.y));
  del2 /= __gcd(abs(del2.x), abs(del2.y));
  return del1 == del2 * (-1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    vector<point> ps(4);
    loop(4) cin >> ps[i];
    ps.push_back(ps[0]);
    cout << "Case " << i + 1 << ": ";
    convex(ps);
    int par = 0;
    loop(2) par += isparallel(ps[i], ps[i + 1], ps[i + 2], ps[i + 3]);
    if (par == 2) {
      set<ll> ds;
      loop(4) ds.insert((ps[i] - ps[i + 1]) * (ps[i] - ps[i + 1]));
      ll ang = (ps[0] - ps[1]) * (ps[1] - ps[2]);
      if (ds.size() == 1) {
        if (ang) cout << "Rhombus";
        else cout << "Square";
      }
      else {
        if (ang) cout << "Parallelogram";
        else cout << "Rectangle";
      }
    }
    else if (par == 1) cout << "Trapezium";
    else cout << "Ordinary Quadrilateral";
    cout << endl;
  }
  return 0;
}

