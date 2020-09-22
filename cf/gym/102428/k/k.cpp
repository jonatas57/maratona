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

struct poly {
  int deg;
  vector<ll> cs;
  poly(int d) : deg(d), cs(d + 1) {}
  poly operator*(poly& p) {
    poly ans(deg + p.deg);
    loop(deg + 1) vloop(j, p.deg + 1) {
      ans[i + j] += cs[i] * p.cs[j];
    }
    return ans;
  }
  ll& operator[](int i) {
    return cs[i];
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  cin >> s;
  vector<poly> ps;
  for (int i = 1;s[i];i++) {
    if (s[i] != s[i - 1]) {
      poly p(1);
      p[0] = -(2 * i + 1);
      p[1] = 1;
      ps.push_back(p);
    }
  }
  poly p(0);
  p[0] = 1;
  each(q, ps) {
    p = p * q;
  }
  ll sig = (s[0] == 'A') xor (p[0] < 0) ? -1 : 1;
  cout << p.deg << endl;
  loop(p.deg + 1) cout << sig * p[p.deg - i] << " ";
  cout << endl;
  return 0;
}

