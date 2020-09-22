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

struct frac {
  int n, d;
  frac(int a = 0, int b = 1) : n(a), d(abs(b)) {
    if (b < 0) n = -n;
  }
  bool operator<(frac f) {
    return n * f.d < d * f.n;
  }
};

int n;
int calc(vector<vector<frac>>& ts, int x, frac t) {
  int ans = 1 << x;
  loop(n) {
    if (t < ts[x][i] and ~ans & (1 << i)) {
      ans |= calc(ts, i, ts[x][i]);
    }
  }
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    cin >> n;
    vector<vector<frac>> ts(n, vector<frac>(n));
    vi a(n);
    loop(n) {
      cin >> a[i];
      vloop(j, i) {
        if (a[i] - a[j] < 0) {
          ts[i][j] = ts[j][i] = frac(i - j, a[j] - a[i]);
        }
      }
    }
    int x = INF, y = 0;
    loop(n) {
      int z = __builtin_popcount(calc(ts, i, frac()));
      x = min(x, z);
      y = max(y, z);
    }
    cout << x << " " << y << endl;
  }
	return 0;
}

