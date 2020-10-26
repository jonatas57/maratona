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
const double EPS = 1e-5;
const double PI = acos(-1);

struct poly {
  int deg;
  vector<double> cs;
  poly(int n) : deg(n), cs(n + 1) {}
  poly operator*(poly& p) {
    poly q(deg + p.deg);
    loop(deg + 1) {
      vloop(j, p.deg + 1) {
        q[i + j] += cs[i] * p[j];
      }
    }
    return q;
  }
  void integral() {
    cs.push_back(0);
    deg++;
    for (int i = deg;i > 0;i--) {
      cs[i] = cs[i - 1] / i;
    }
    cs[0] = 0;
  }
  double eval(double x) {
    double val = 0;
    double v = 1;
    loop(deg + 1) {
      val += v * cs[i];
      v *= x;
    }
    return PI * val;
  }
  double& operator[](int i) {
    return cs[i];
  }
  friend istream& operator>>(istream& is, poly& p) {
    loop(p.deg + 1) is >> p[i];
    return is;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  for (int t = 1;cin >> n;t++) {
    poly q(n);
    double low, high;
    ll inc;
    cin >> q >> low >> high >> inc;
    poly p = q * q;
    p.integral();

    double v = p.eval(high) - p.eval(low);
    vector<double> ans;
    double bot = p.eval(low);
    loop(8) {
      double trg = inc * (i + 1);
      if (trg > EPS + v) break;
      double l = ans.empty() ? low : ans.back(), r = high;
      while (l + EPS < r) {
        double mid = (l + r) / 2;
        double val = p.eval(mid) - bot;
        if (val + EPS < trg) l = mid + EPS;
        else if (val > EPS + trg) r = mid;
        else l = r = mid;
      }
      ans.push_back(l);
    }
    cout << "Case " << t << ": " << fixed << setprecision(2) << v << endl;
    if (ans.empty()) cout << "insufficient volume";
    bool f = true;
    each(x, ans) {
      if (!f) cout << " ";
      f = false;
      cout << fixed << setprecision(2) << x - low;
    }
    cout << endl;
  }
  return 0;
}

