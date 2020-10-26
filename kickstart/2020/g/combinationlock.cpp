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
    int w, n;
    cin >> w >> n;
    vi a(w);
    loop(w) cin >> a[i];
    sort(iter(a));
    ll sum = 0;
    int med = (w - 1) / 2;
    each(x, a) sum += abs(x - a[med]);
    ll ans = sum;
    loop(w - 1) {
      sum -= abs(a[i] - a[med]);
      sum += abs(a[i] + n - a[med]);
      a.push_back(a[i] + n);
      sum -= (a[med + 1] - a[med]) * (w & 1 ? 1 : 2);
      med++;
      ans = min(ans, sum);
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;
  }
  return 0;
}
