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

  ll n;
  cin >> n;
  vector<ll> t(1, 1), f(1, 1);
  while (t.back() <= n / 3) t.push_back(3 * t.back());
  while (f.back() <= n / 5) f.push_back(5 * f.back());
  int a = t.size(), b = f.size();
  vector<ii> ans;
  for (int i = 1;i < a;i++) for (int j = 1;j < b;j++) {
    if (t[i] + f[j] == n) {
      ans.emplace_back(i, j);
    }
  }
  if (ans.empty()) cout << -1 << endl;
  else cout << ans[0].first << " " << ans[0].second << endl;
  return 0;
}

