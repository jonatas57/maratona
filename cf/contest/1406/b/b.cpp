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
    loop(n) cin >> a[i];
    sort(iter(a));
    vector<ll> pos(5), neg(5);
    loop(5) {
      pos[i] = (i ? pos[i - 1] : 1) * a[n - i - 1];
      neg[i] = (i ? neg[i - 1] : 1) * a[i];
    }
    ll ans = -INFLL;
    for (int i = 0;i <= 2;i += 2) {
      ans = max(ans, pos[i] * neg[3 - i]);
    }
    ans = max({ans, pos[4], neg[4]});
    cout << ans << endl;
  }
  return 0;
}

