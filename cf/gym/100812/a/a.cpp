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

  int n;
  cin >> n;
  vector<ll> sal(n, 0);
  ll x;
  loop(n) vloop(j, n) {
    cin >> x;
    sal[i] += x;
    sal[j] -= x;
  }
  priority_queue<pair<ll, int>> pos, neg;
  loop(n) {
    if (sal[i] > 0) pos.emplace(sal[i], i);
    else if (sal[i] < 0) neg.emplace(-sal[i], i);
  }
  vector<vector<ll>> ans(n, vector<ll>(n, 0));
  while (!pos.empty()) {
    auto [p, i] = pos.top();
    auto [q, j] = neg.top();
    pos.pop(), neg.pop();
    ll x = min(p, q);
    ans[i][j] = x;
    p -= x;
    q -= x;
    if (p) pos.emplace(p, i);
    if (q) neg.emplace(q, j);
  }
  each(v, ans) {
    each(x, v) {
      cout << x << " ";
    }
    cout << endl;
  }
  return 0;
}

