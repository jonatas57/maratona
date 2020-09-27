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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    mii del, last;
    vi ans(n, INF);
    vi a(n);
    loop(n) {
      cin >> a[i];
      if (!last.count(a[i])) last[a[i]] = -1;
      del[a[i]] = max(del[a[i]], i - last[a[i]]);
      last[a[i]] = i;
    }
    loop(n) {
      del[a[i]] = max(del[a[i]], n - last[a[i]]);
      ans[del[a[i]] - 1] = min(ans[del[a[i]] - 1], a[i]);
    }
    loop(n - 1) ans[i + 1] = min(ans[i], ans[i + 1]);
    each(x, ans) cout << (x == INF ? -1 : x) << " ";
    cout << endl;
  }
  return 0;
}

