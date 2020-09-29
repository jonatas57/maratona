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
  mii cnta, cntb;
  int x;
  loop(n) cin >> x, cnta[x]++;
  loop(n) cin >> x, cntb[x]++;
  vector<ii> a(iter(cnta)), b(iter(cntb));
  int l = a.size();
  int ans = INF;
  loop(l) {
    int aux = (m + b[i].first - a[0].first) % m;
    bool ok = true;
    for (int j = 0;ok and j < l;j++) {
      if (a[j].second != b[(i + j) % l].second) ok = false;
      if ((a[j].first + aux) % m != b[(i + j) % l].first) ok = false;
    }
    if (ok) ans = min(aux, ans);
  }
  cout << ans << endl;
  return 0;
}

