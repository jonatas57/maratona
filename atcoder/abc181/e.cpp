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

  int n, m;
  cin >> n >> m;
  vector<ll> hs(n), ws(m);
  loop(n) cin >> hs[i];
  loop(m) cin >> ws[i];
  sort(iter(hs));
  vector<ll> accl(n + 1, 0), accr(n + 1, 0);
  for (int i = 1;i < n;i += 2) {
    accl[i + 1] = accl[i - 1] + hs[i] - hs[i - 1];
    accr[n - i - 1] = accr[n - i + 1] + hs[n - i] - hs[n - i - 1];
  }
  sort(iter(ws));
  ll ans = INFLL;
  for (int i = 0, j = 0;i < m;i++) {
    while (j < n and ws[i] > hs[j]) j++;
    ll aux;
    if (j & 1) {
      aux = ws[i] - hs[j - 1] + accl[j - 1] + accr[j];
    }
    else {
      aux = hs[j] - ws[i] + accl[j] + accr[j + 1];
    }
    ans = min(aux, ans);
  }
  cout << ans << endl;
  return 0;
}

