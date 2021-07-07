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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

double solve(double c, double m, double p, double v) {
  double x = min(v, c);
  double y = min(v, m);
  double ans = 1;
  if (c >= EPS) ans += c * solve(c - x, m < EPS ? 0 : (m + x / 2), m < EPS ? p + x : (p + x / 2), v);
  if (m >= EPS) ans += m * solve(c < EPS ? 0 : (c + y / 2), m - y, c < EPS ? p + y : (p + y / 2), v);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    double c, m, p, v;
    cin >> c >> m >> p >> v;
    cout << fixed << setprecision(12) << solve(c, m, p, v) << endl;
  }
  return 0;
}

