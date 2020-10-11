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
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
};

istream& operator>>(istream& is, point& p) {
  is >> p.x >> p.y;
  return is;
}

struct line {
  point p, q;
  int a, b, c;
  line(point& x, point& y) : p(x), q(y) {
    point del = p - q;
    a = -del.y;
    b = del.x;
    c = -(a * p.x + b * p.y);
  }
  bool inside(point& o) {
    if (a * o.x + b * o.y + c) return false;
    return min(p.x, q.x) <= o.x and o.x <= max(p.x, q.x) and min(p.y, q.y) <= o.y and o.y <= max(p.y, q.y);
  }
};

ll cross(point& o, point& p, point& q) {
  point a = p - o, b = q - o;
  return a.x * b.y - a.y * b.x;
}

bool intersect(line& r, line& s) {
  if (r.inside(s.p) or r.inside(s.q) or s.inside(r.p) or s.inside(r.q)) return true;
  ll a = cross(r.p, r.q, s.p) * cross(r.p, r.q, s.q);
  ll b = cross(s.p, s.q, r.p) * cross(s.p, s.q, r.q);
  return (a < 0) and (b < 0);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while (cin >> n and n) {
    vector<line> ls;
    point p, q;
    loop(n) {
      cin >> p >> q;
      ls.emplace_back(p, q);
    }
    int ans = 0, zero = 0;
    for (int i = 0;i < n;i++) {
      int cnt = 0;
      for (int j = 0;j < n;j++) {
        if (i == j) continue;
        if (intersect(ls[i], ls[j])) cnt++;
      }
      ans += cnt;
      zero += cnt == 0;
    }
    ans /= 2;
    ans += zero * 2;
    cout << ans << endl;
  }
  return 0;
}

