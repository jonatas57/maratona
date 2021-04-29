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
  vector<ll> a(n), b(n);
  ll sum = 0;
  loop(n) cin >> a[i];
  loop(n) cin >> b[i], sum += a[i] * b[i];
  ll maxdel = 0;
  vector<vector<ll>> memo(n);
  for (int l = 2, i = 0;l <= n;l++, i++) {
    for (int j = 0;j <= n - l;j++) {
      memo[i].push_back(a[j] * b[j + l - 1] + b[j] * a[j + l - 1] - a[j] * b[j] - a[j + l - 1] * b[j + l - 1]);
      if (l > 3) {
        memo[i][j] += memo[i - 2][j + 1];
      }
      maxdel = max(maxdel, memo[i][j]);
    }
  }
  cout << sum + maxdel << endl;
  return 0;
}

