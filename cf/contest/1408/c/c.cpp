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
const double EPS = 1e-8;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, l;
    cin >> n >> l;
    vi a(n);
    loop(n) cin >> a[i];
    double p1 = 0, p2 = l, time = 0;
    int v1 = 1, v2 = 1;
    for (int i = 0, j = n - 1;i <= j;) {
      double t1 = abs(a[i] - p1) / v1;
      double t2 = abs(a[j] - p2) / v2;
      double x = t1 + EPS < t2 ? t1 : t2;
      time += x;
      p1 += x * v1;
      p2 -= x * v2;
      if (abs(t1 - x) < EPS) i++, v1++;
      if (abs(t2 - x) < EPS) j--, v2++;
    }
    double ans = time + abs(p2 - p1) / (v1 + v2);
    cout << fixed << setprecision(15) << ans << endl;
  }
  return 0;
}

