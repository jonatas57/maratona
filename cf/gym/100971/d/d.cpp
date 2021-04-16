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

  int n;
  cin >> n;
  vector<tuple<int, int, int>> a;
  loop(n) {
    int x, p;
    cin >> x >> p;
    a.emplace_back(p, x, i);
  }
  sort(riter(a));
  set<tuple<int, int, int>> maj;
  vi ans(n, -1);
  for (auto& [p, x, i] : a) {
    auto r = maj.lower_bound(make_tuple(x, -1, -1));
    auto l = maj.upper_bound(make_tuple(x, -1, -1));
    int dist = INF, lastp = 0;
    if (r != maj.end()) {
      int x2;
      tie(x2, lastp, ans[i]) = *r;
      dist = abs(x - x2);
    }
    if (l != maj.begin()) {
      l--;
      auto [x2, p2, i2] = *l;
      int dist2 = abs(x2 - x);
      if (dist2 == dist ? p2 > lastp : dist2 < dist) {
        ans[i] = i2;
      }
    }
    maj.emplace(x, p, i + 1);
  }
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

