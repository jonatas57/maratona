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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<vi> ids(n + 1);
  loop(n) {
    int x;
    cin >> x;
    if (x <= n) ids[x].push_back(i + 1);
  }
  vi pos;
  int lim = n;
  for (int i = 1;i <= lim;i++) {
    int x = ids[i].size();
    lim -= x;
    if (x >= i) pos.push_back(i);
  }
  int l, r;
  loop(m) {
    cin >> l >> r;
    int ans = 0;
    each(x, pos) {
      ans += (upper_bound(iter(ids[x]), r) - lower_bound(iter(ids[x]), l)) == x;
    }
    cout << ans << endl;
  }
  return 0;
}

