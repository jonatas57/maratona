#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

vi price;
vi qtd;
vector<vi> dp;

int solve(int at, int x) {
  if (x < 0) return 0;
  if (dp[at][x] == INF) {
    if (at == 0) dp[at][x] = x * price[at];
    else {
      for (int i = x, p = 0;;i -= qtd[at], p += price[at]) {
        dp[at][x] = min(dp[at][x], solve(at - 1, i) + p);
        if (i < 0) break;
      }
    }
  }
  return dp[at][x];
}

int main() {
  int p, c, n;
  char x;
  for (int t = 1;cin >> p >> x >> c >> n;t++) {
    int q;
    dp.assign(n + 1, vi(101, INF));
    price.assign(1, p * 100 + c);
    qtd.assign(1, 1);
    loop(n) {
      cin >> q >> p >> x >> c;
      qtd.push_back(q);
      price.push_back(100 * p + c);
    }
    getchar();
    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    int k;
    cout << "Case " << t << ":" << endl;
    while (ss >> k) {
      int ans = solve(n, k);
      cout << "Buy " << k << " for $" << ans / 100 << "." << setw(2) << setfill('0') << ans % 100 << endl;
    }
  }
	return 0;
}

