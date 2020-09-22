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

vector<vector<ll>> dp;
vector<vi> par;

ll solve(vector<ii>& vs, int l, int r) {
  if (dp[l][r] == INF) {
    if (l == r) dp[l][r] = 0;
    else {
      for (int i = l;i < r;i++) {
        int a = solve(vs, l, i);
        int b = solve(vs, i + 1, r);
        int x = a + b + vs[l].first * vs[i].second * vs[r].second;
        if (x < dp[l][r]) {
          dp[l][r] = x;
          par[l][r] = i;
        }
      }
    }
  }
  return dp[l][r];
}

string getAns(int l, int r) {
  if (l == r) return "A" + to_string(l + 1);
  int x = par[l][r];
  return "(" + getAns(l, x) + " x " + getAns(x + 1, r) + ")";
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  for (int i = 1;cin >> n and n;i++) {
    vector<ii> vs(n);
    loop(n) cin >> vs[i].first >> vs[i].second;
    dp.assign(n, vector<ll>(n, INF));
    par.assign(n, vi(n, -1));
    solve(vs, 0, n - 1);
    cout << "Case " << i << ": " << getAns(0, n - 1) << endl;
  }
	return 0;
}

