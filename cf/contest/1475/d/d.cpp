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
    int n, m;
    cin >> n >> m;
    priority_queue<ll> one, two;
    vector<ll> a(n);
    loop(n) cin >> a[i];
    ll f = 0, c = 0;
    loop(n) {
      ll x;
      cin >> x;
      if (x == 1) one.push(a[i]);
      else {
        two.push(-a[i]);
        f += a[i];
        c += 2;
      }
    }
    while (!one.empty() and f < m) {
      f += one.top();
      c++;
      one.pop();
    }
    ll ans = f < m ? -1 : c;
    while (!two.empty()) {
      f += two.top();
      c -= 2;
      two.pop();
      while (!one.empty() and f < m) {
        f += one.top();
        c++;
        one.pop();
      }
      if (f >= m) ans = min(ans, c);
      else break;
    }
    cout << ans << endl;
  }
  return 0;
}

