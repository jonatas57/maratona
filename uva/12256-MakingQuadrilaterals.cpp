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
const int N = 3;

vector<vector<ll>> operator*(vector<vector<ll>>& a, vector<vector<ll>>& b) {
  vector<vector<ll>> c(N, vector<ll>(N, 0));
  loop(N) vloop(j, N) vloop(k, N) {
    c[i][j] += a[i][k] * b[k][j];
  }
  return c;
}

vector<vector<ll>> xp(vector<vector<ll>>& b, ll e) {
  if (e == 1) return b;
  vector<vector<ll>> c = xp(b, e >> 1);
  c = c * c;
  if (e & 1) c = c * b;
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int x;
  vector<vector<ll>> base = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
  for (int t = 1;cin >> x and x;t++) {
    vector<vector<ll>> c = xp(base, x - 3);
    ll ans = 0;
    loop(N) ans += c[0][i];
    cout << "Case " << t << ": " << ans << endl;
  }
  return 0;
}

