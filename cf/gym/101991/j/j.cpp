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

struct point {
  double x, y, z;
  point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
  point operator-(point p) {
    return point(x - p.x, y - p.y, z - p.z);
  }
  bool operator==(point p) {
    return abs(x - p.x) < EPS and abs(y - p.y) < EPS and abs(z - p.z) < EPS;
  }
};

istream& operator>>(istream& is, point& p) {
  is >> p.x >> p.y >> p.z;
  return is;
}

double norm(point p) {
  return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

double dot(point& p, point& q) {
  return p.x * q.x + p.y * q.y;
}

double cross(point& p, point& q) {
  return p.x * q.y - p.y * q.x;
}

double dist(point a, point b) {
  return norm(a - b);
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

point mult(vector<vector<double>>& rot, point a) {
  return point(rot[0][0] * a.x + rot[0][1] * a.y + rot[0][2] * a.z,
               rot[1][0] * a.x + rot[1][1] * a.y + rot[1][2] * a.z,
               rot[2][0] * a.x + rot[2][1] * a.y + rot[2][2] * a.z);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  freopen("jupiter.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    point n, A;
    ll l, h;
    cin >> n >> A >> l >> h;

    double d = l / sqrt(3);
    point a(-d, 0, 0), b(d / 2, -l / 2.0, 0), c(d / 2, l / 2.0, 0);

    double len = norm(n);
    double beta = asin(n.x / len), alfa = asin(-n.y / (len * cos(beta)));
    auto rotx = getRotX(alfa);
    auto roty = getRotY(beta);
    
    auto unrotx = getRotX(-alfa);
    auto unroty = getRotY(-beta);
    point p = mult(unroty, mult(unrotx, A));
    double gamma = acos(dot(a, p) / (norm(a) * norm(p)));
    if (cross(a, p) / (norm(a) * norm(p)) + EPS< 0) {
      gamma = -gamma;
    }
    auto rotz = getRotZ(gamma);

    a = mult(rotx, mult(roty, mult(rotz, a)));
    b = mult(rotx, mult(roty, mult(rotz, b)));
    c = mult(rotx, mult(roty, mult(rotz, c)));

    point base(0, 0, -h);
    cout << fixed << setprecision(6) << dist(base, a) << " ";
    cout << fixed << setprecision(6) << dist(base, b) << " ";
    cout << fixed << setprecision(6) << dist(base, c) << endl;
  }
  return 0;
}

