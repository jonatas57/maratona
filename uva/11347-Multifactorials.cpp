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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  ll maxa = 1e18;
  loop(t) {
    int n;
    string s;
    cin >> n >> s;
    int k = s.length();
    map<int, int> fs;
    for (int i = n;i > 1;i -= k) {
      int x = i;
      for (int j = 2;j * j <= x;j++) {
        while (x % j == 0) {
          fs[j]++;
          x /= j;
        }
      }
      if (x > 1) fs[x]++;
    }
    ll ans = 1;
    each(p, fs) {
      ll e = p.second + 1;
      if (ans > maxa / e) {
        ans = INFLL;
        break;
      }
      ans *= e;
    }
    cout << "Case " << i + 1 << ": ";
    if (ans == INFLL) cout << "Infinity" << endl;
    else cout << ans << endl;
  }
	return 0;
}

