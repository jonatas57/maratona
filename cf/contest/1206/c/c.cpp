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
#define keach(k, v, s)     for(auto& [k, v] : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define cc(x)              cerr << #x << " = " << x << endl;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  if (n & 1) {
    cout << "YES\n";
    vi pos(2 * n);
    bool p = true;
    loop(n) {
      if (p) {
        pos[i << 1] = i;
        pos[i << 1 | 1] = n + i;
      }
      else {
        pos[i << 1 | 1] = i;
        pos[i << 1] = n + i;
      }
      p = !p;
    }
    vi ans(2 * n);
    loop(2 * n) {
      ans[pos[i]] = i + 1;
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  else {
    cout << "NO\n";
  }
	return 0;
}
