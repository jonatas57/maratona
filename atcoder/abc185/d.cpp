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
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  int lastx = 0;
  vi as(m);
  vector<ii> a;
  int sz = INF;
  loop(m) cin >> as[i];
  sort(iter(as));
  each(x, as) {
    if (lastx != x - 1) {
      a.emplace_back(lastx + 1, x - 1);
      sz = min(sz, x - 1 - lastx);
    }
    lastx = x;
  }
  if (lastx != n) {
    a.emplace_back(lastx + 1, n);
    sz = min(sz, n - lastx);
  }
  int ans = 0;
  for (auto& [l, r] : a) {
    ans += (r - l + sz) / sz;
  }
  cout << ans << endl;
  return 0;
}

