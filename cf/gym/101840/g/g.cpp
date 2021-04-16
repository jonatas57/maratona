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
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("glorious.in", "r", stdin);
  
  int t;
  cin >> t;
  loop(t) {
    ll n, r, k;
    cin >> n >> r >> k;
    double alfa = 2 * PI / k;
    double a1 = k * r * r * tan(alfa / 2), a2 = k * r * r * sin(alfa) / 2;
    double p = a1 / a2;
    double ans = (a1 - PI * r * r) * (1 - pow(p, n)) / (1 - p);
    cout << "Case " << i + 1 << ": " << fixed << setprecision(5) << ans << endl;
  }
  return 0;
}

