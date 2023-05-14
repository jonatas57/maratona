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

const ll mod = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n), b(n);
    loop(n) cin >> a[i];
    loop(n) cin >> b[i];
    sort(iter(a));
    sort(iter(b));
    ll ans = 1;
    int qtd = 0;
    each(x, a) {
      ll p = lower_bound(iter(b), x) - b.begin();
      ans *= p - qtd;
      ans %= mod;
      qtd++;
    }
    cout << ans << endl;
  }
  return 0;
}

