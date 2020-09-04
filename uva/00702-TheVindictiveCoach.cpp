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

vector<vector<ll>> ans(25, vector<ll>(25, -1));
ll f(int m, int n, bool down = true) {
  if (!down) return f(n + 1 - m, n);
  if (ans[m][n] == -1) {
    if (m == 1 and n == 1) ans[n][m] = 1;
    else {
      ans[m][n] = 0;
      for (int i = 1;i < m;i++) {
        ans[m][n] += f(i, n - 1, !down);
      }
    }
  }
  return ans[m][n];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  while (cin >> n >> m) {
    if (m == 1) cout << f(1, max(1, n - 2), false) << endl;
    else cout << f(m, n) << endl;
  }
	return 0;
}

