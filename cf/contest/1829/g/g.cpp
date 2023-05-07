#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  vector<ll> qtd(2024);
  iota(iter(qtd), 0);
  partial_sum(iter(qtd), qtd.begin());
  loop(t) {
    int n;
    cin >> n;
    int r = lower_bound(iter(qtd), n) - qtd.begin();
    int c = n - qtd[r - 1];
    ll ans = 0;
    for (int i = r, id = 0;i > 0;i--, id++) {
      for (int j = max(1, c - id);j <= min(c, i);j++) {
        ll x = qtd[i - 1] + j;
        ans += x * x;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

