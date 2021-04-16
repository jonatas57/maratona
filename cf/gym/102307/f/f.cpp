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

struct frac {
  ll n, d;
  frac(int a = 0, int b = 1) : n(a), d(abs(b)) {
    if (b < 0) n = -n;
    simpl();
  }
  void simpl() {
    ll m = gcd(n, d);
    if (m) {
      n /= m;
      d /= m;
    }
  }
  void operator+=(frac& f) {
    n = n * f.d + d * f.n;
    d *= f.d;
    simpl();
  }
  friend ostream& operator<<(ostream& os, frac& f) {
    os << f.n << "/" << f.d;
    return os;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  while (cin >> s) {
    frac f;
    int n = 0, d = 0;
    bool den = false;
    int sgn = 1, inv = 1;
    stack<int> invs;
    invs.push(1);
    for (int i = 0;;i++) {
      if (isdigit(s[i])) {
        if (den) d = 10 * d + s[i] - '0';
        else n = 10 * n + s[i] - '0';
      }
      else if (s[i] == '/') {
        den = true;
      }
      else if (s[i] == '(') {
        invs.push(sgn);
        inv *= sgn;
        sgn = 1;
      }
      else {
        if (d) {
          frac g(n * inv * sgn, d);
          n = d = 0;
          den = false;
          f += g;
          sgn = 1;
        }
        if (s[i] == '-') {
          sgn = -1;
        }
        else if (s[i] == ')') {
          inv *= invs.top();
          invs.pop();
        }
        else if (s[i] == '+') {
          sgn = 1;
        }
        else if (!s[i]) break;
      }
    }
    cout << f << endl;
  }
  return 0;
}

