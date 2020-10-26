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
    ll n, k;
    cin >> n >> k;
    ll l, r;
    vector<pair<ll, ll>> q;
    loop(n) {
      cin >> l >> r;
      q.emplace_back(l, r);
    }
    sort(iter(q));
    ll ans = 0, dl = 0;
    each(p, q) {
      if (dl < p.second) {
        ll st = max(dl, p.first);
        ll x = (p.second - st + k - 1) / k;
        ans += x;
        dl = st + x * k;
      }
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}

