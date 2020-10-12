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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  double len = 10000;
  while (cin >> n >> m) {
    m += n;
    vector<double> a(n, 0), b(m, 0);
    loop(n) a[i] = i * len / n;
    loop(m) b[i] = i * len / m;
    double ans = 0;
    vb used(m, false);
    used[0] = true;
    for (int i = 1, j = 1;i < n;i++) {
      while (j < m and b[j] + EPS < a[i]) j++;
      double del = INF;
      if (!used[j]) del = min(del, b[j] - a[i]);
      if (!used[j - 1]) del = min(del, a[i] - b[j - 1]);
      ans += del;
      used[j - (abs(del - a[i] + b[j - 1]) < EPS)] = true;
    }
    cout << fixed << setprecision(4) << ans << endl;
  }
  return 0;
}

