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
    int n;
    cin >> n;
    vector<ll> a(n);
    ll l = 0, r = 1e10, sum = 0;
    loop(n) {
      cin >> a[i];
      l = max(l, a[i]);
      sum += a[i];
    }
    ll ans = INFLL;
    while (l < r) {
      ll mid = avg(l, r);
      ll b = mid * (n - 1);
      ll aux = 0;
      loop(n) {
        ll x = b - (sum - a[i]);
        if (x < a[i]) {
          aux = INFLL;
          break;
        }
        else aux = max(aux, x - a[i]);
      }
      if (aux < ans) {
        ans = aux;
        r = mid;
      }
      else l = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}

