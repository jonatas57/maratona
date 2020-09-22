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

ll xp(ll b, ll e) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

ll inv(ll x) {
  return xp(x, mod - 2);
}

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a % mod), d(b % mod) {}
  frac operator*(frac f) {
    return frac(n * f.n, d * f.d);
  }
  frac operator+(frac f) {
    return frac(n * f.d + f.n * d, d * f.d);
  }
  ll val() {
    return n * inv(d) % mod;
  }
  bool operator<(ll x) {
    return n < x * d;
  }
};

frac operator-(int x, frac f) {
  return frac(x) + frac(-f.n, f.d);
}

string s;
vector<frac> ps;
vector<vector<frac>> dp;

frac solve(int n, int m) {// probabilidade de a string t[0..n] ter s[0..m] como subsequencia
  if (dp[n][m] < 0) {
    if (m == 0) dp[n][m] = 1;
    else if (n < m) dp[n][m] = 0;
    else dp[n][m] = solve(n - 1, m) * (1 - ps[s[m - 1] - 'a']) + solve(n - 1, m - 1) * ps[s[m - 1] - 'a'];
  }
  return dp[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  cin >> s;
  loop(26) {
    int a, b;
    cin >> a >> b;
    ps.emplace_back(a, b);
  }
  dp.resize(n + 1, vector<frac>(m + 1, -1));
  cout << solve(n, m).val() << endl;
  return 0;
}

