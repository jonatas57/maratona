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
    int a, b, k;
    cin >> a >> b >> k;
    vi bs(k), gs(k), cntb(a, 0), cntg(b, 0);
    loop(k) {
      cin >> bs[i];
      cntb[bs[i] - 1]++;
    }
    loop(k) {
      cin >> gs[i];
      cntg[gs[i] - 1]++;
    }
    ll ans = 0;
    loop(k) {
      ans += k - i - cntb[bs[i] - 1] - cntg[gs[i] - 1] + 1;
      cntb[bs[i] - 1]--;
      cntg[gs[i] - 1]--;
    }
    cout << ans << endl;
  }
  return 0;
}

