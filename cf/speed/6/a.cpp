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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m, a, b;
  cin >> n >> m >> a >> b;
  a--, b--;
  int la = a / m, ca = a % m, lb = b / m, cb = b % m;
  int ans;
  if (la == lb) ans = 1;
  else if (la == lb - 1) {
    ans = ((ca == 0 and (cb == m - 1 || b == n - 1)) ? 1 : 2);
  }
  else {
    if (ca == 0 and (cb == m - 1 || b == n - 1)) ans = 1;
    else if (ca == cb + 1 || ca == 0 || (cb == m - 1 || b == n - 1)) ans = 2;
    else ans = 3;
  }
  cout << ans << endl;
	return 0;
}

/*
*****
*****

*/