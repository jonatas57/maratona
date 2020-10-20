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
    map<int, vi> gs;
    int x;
    loop(n) {
      cin >> x;
      gs[x].push_back(i + 1);
    }
    if (gs.size() == 1) {
      cout << "NO" << endl;
      continue;
    }
    int m, sz = INF;
    for (auto& [g, ps] : gs) {
      int x = ps.size();
      if (x < sz) m = g, sz = x;
    }
    vector<ii> ans;
    for (auto& [g, ps] : gs) {
      if (g == m) continue;
      each(x, ps) ans.emplace_back(gs[m][0], x);
    }
    for (auto& [g, ps] : gs) {
      if (g == m) continue;
      for (int i = 1;i < gs[m].size();i++) ans.emplace_back(gs[m][i], ps[0]);
      break;
    }
    cout << "YES" << endl;
    for (auto& [u, v] : ans) cout << u << " " << v << endl;
  }
  return 0;
}

