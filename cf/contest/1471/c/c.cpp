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
    vector<ll> k(n), c(m);
    loop(n) cin >> k[i], k[i]--;
    loop(m) cin >> c[i];
    sort(iter(k));
    priority_queue<int> minc, pres;
    ll sum = 0;
    int lastc = 0;
    loop(n) {
      while (lastc <= k[i]) minc.push(-c[lastc++]);
      ll x = c[k[i]], y = minc.empty() ? INF : -minc.top(), z = pres.empty() ? INF : -pres.top();
      if (x <= y and x <= z) {
        sum += x;
      }
      else if (y < x and y <= z) {
        sum += y;
        minc.pop();
        pres.push(-x);
      }
      else {
        sum += z;
        pres.pop();
        pres.push(-x);
      }
    }
    cout << sum << endl;
  }
  return 0;
}

