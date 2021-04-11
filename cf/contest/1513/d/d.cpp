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

  int t;
  cin >> t;
  loop(t) {
    ll n, p;
    cin >> n >> p;
    map<int, vi> pos;
    set<ll> val;
    vi a(n);
    ll cs = n;
    loop(n) {
      cin >> a[i];
      pos[a[i]].push_back(i);
      val.insert(a[i]);
    }
    vb used(n, false);
    ll ans = 0;
    each(x, val) {
      if (x >= p) break;
      each(y, pos[x]) {
        if (used[y]) continue;
        int l = y, r = y;
        while (l >= 0 and a[l] % x == 0 and !used[l]) l--;
        while (r < n and a[r] % x == 0 and !used[r]) r++;
        l += l < 0 or !used[l] or a[l] % x;
        r -= r >= n or !used[r] or a[r] % x;
        ll qtd = r - l + 1;
        ans += (qtd - 1) * x;
        cs -= qtd - 1;
        for (int i = l;i <= r;i++) used[i] = true;
      }
    }
    ans += (cs - 1) * p;
    cout << ans << endl;
  }
  return 0;
}

