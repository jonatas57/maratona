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
    vector<ll> a(n);
    ll sum = 0;
    loop(n) cin >> a[i], sum += a[i];
    if (sum % n) {
      cout << -1 << endl;
      continue;
    }
    sum /= n;
    vector<tuple<int, int, int>> ans;
    priority_queue<tuple<ll, ll, int>> q;
    for (int i = 1;i < n;i++) {
      ll cost = 0;
      int x = a[i] % (i + 1);
      if (x) {
        cost = i + 1 - x;
      }
      q.emplace(-cost, a[i], i);
    }
    while (!q.empty()) {
      auto [cost, del, id] = q.top();
      cost = abs(cost);
      if (cost) {
        ans.emplace_back(1, id + 1, cost);
        a[0] -= cost;
        a[id] += cost;
      }
      ll x = a[id] / (id + 1);
      ans.emplace_back(id + 1, 1, x);
      a[0] += a[id];
      a[id] = 0;
      q.pop();
    }
    for (int i = 1;i < n;i++) {
      ans.emplace_back(1, i + 1, sum);
      a[i] += sum;
      a[0] -= sum;
    }
    bool pos = true;
    if (!pos) {
      cout << -1 << endl;
      continue;
    }
    cout << ans.size() << endl;
    for (auto& [a, b, c] : ans) cout << a << " " << b << " " << c << endl;
  }
  return 0;
}

