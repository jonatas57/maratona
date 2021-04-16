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
const double EPS = 1e-8;
const double PI = acos(-1);
const int R = 6371;
const double C = 299792.458;

struct point {
  double x, y, z;
  point(int, double r = 0, double lat = 0, double lon = 0) : x(r * cos(lat) * cos(lon)), y(r * cos(lat) * sin(lon)), z(r * sin(lat)) {}
  point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y, z - p.z);
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y + z * p.z;
  }
};

double rad(double x) {
  return x * PI / 180.0;
}

vector<vector<double>> getRotX(double a) {
  return {{1, 0, 0}, {0, cos(a), -sin(a)}, {0, sin(a), cos(a)}};
}

vector<vector<double>> getRotY(double a) {
  return {{cos(a), 0, sin(a)}, {0, 1, 0}, {-sin(a), 0, cos(a)}};
}

vector<vector<double>> getRotZ(double a) {
  return {{cos(a), -sin(a), 0}, {sin(a), cos(a), 0}, {0, 0, 1}};
}

point mult(vector<vector<double>>&& rot, point a) {
  point p;
  p.x = rot[0][0] * a.x + rot[0][1] * a.y + rot[0][2] * a.z;
  p.y = rot[1][0] * a.x + rot[1][1] * a.y + rot[1][2] * a.z;
  p.z = rot[2][0] * a.x + rot[2][1] * a.y + rot[2][2] * a.z;
  return p;
}

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int s;
  double lat, lon;
  cin >> s >> lon >> lat;
  point pos((int)1, R, rad(lat), rad(lon));
  loop(s) {
    double phi, psi, r, x;
    cin >> phi >> psi >> r >> x;
    phi = rad(phi);
    psi = rad(psi - 90);
    point p((int)1, r);
    x = -x;
    p = mult(getRotZ(phi), mult(getRotX(psi), mult(getRotY(2 * PI * x), p)));
    double cr = pos * (p - pos);
    if (cr < -EPS) {
      cout << "no signal" << endl;
      continue;
    }
    double ans = dist(p, pos) / C;
    cout << fixed << setprecision(8) << ans << endl;
  }
  return 0;
}

