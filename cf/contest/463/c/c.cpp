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

  int n;
  cin >> n;
  vector<vector<ll>> a(n, vector<ll>(n));
  loop(n) vloop(j, n) cin >> a[i][j];
  vector<ll> d1(n + n + 1, 0), d2(n + n + 1, 0);
  loop(n) {
    vloop(j, n) {
      d1[i + j] += a[i][j];
      d2[n - 1 - i + j] += a[i][j];
    }
  }
  ll m1 = -1, m2 = -1;
  int x1, x2, y1, y2;
  loop(n) {
    vloop(j, n) {
      a[i][j] = d1[i + j] + d2[n - 1 - i + j] - a[i][j];
      if ((i + j) & 1) {
        if (a[i][j] > m1) m1 = a[i][j], x1 = i + 1, y1 = j + 1;
      }
      else {
        if (a[i][j] > m2) m2 = a[i][j], x2 = i + 1, y2 = j + 1;
      }
    }
  }
  cout << m1 + m2 << endl;
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  return 0;
}

