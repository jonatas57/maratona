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

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int n;
  cin >> n;
  vector<pair<ll, ll>> lr;
  loop(n) {
    ll l, r;
    cin >> l >> r;
    lr.emplace_back(r, l);
  }
  sort(riter(lr));
  priority_queue<ll> q;
  ll ans = 0, val = 0, fix = 0, qtd = 0;
  for (auto& [r, l] : lr) {
    while (!q.empty() and q.top() > r) {
      fix += q.top();
      qtd--;
      q.pop();
    }
    qtd++;
    ll don = fix + qtd * r;
    if (don >= val) {
      val = don;
      ans = r;
    }
    q.push(l);
  }
  cout << ans << " " << val << endl;
  return 0;
}

