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
const ll R = 6371009;

double rad(double x) {
  return x * acos(-1) / 180.0;
}

struct point {
  double x, y, z;
  point(double lat, double lon) : x(R * cos(rad(lat)) * cos(rad(lon))), y(R * cos(rad(lat)) * sin(rad(lon))), z(R * sin(rad(lat))) {}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y, z - p.z);
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y + z * p.z;
  }
};

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

double angle(point& u, point& v) {
  return acos(u * v / (R * R));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  loop(n) {
    double a, b, c, d;
    cin >> a >> b >> c >> d;
    point p(a, b), q(c, d);
    double x = angle(p, q) * R, y = dist(p, q);
    cout << fixed << setprecision(0) << x - y << endl;
  }
  return 0;
}

