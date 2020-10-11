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

  int n;
  while (cin >> n and n) {
    int ans = 0, tot = 0;
    vector<ii> ps(n);
    loop(n) cin >> ps[i].first >> ps[i].second;
    int c = n / 2;
    loop(n) {
      if (ps[i].first == ps[c].first or ps[i].second == ps[c].second) continue;
      ans += (ps[i].first > ps[c].first) == (ps[i].second > ps[c].second);
      tot++;
    }
    cout << ans << " " << tot - ans << endl;
  }
  return 0;
}

