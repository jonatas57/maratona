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
  loop(t) {
    int n;
    cin >> n;
    vi msbi(n + 1);
    vector<vi> bs(30, vi(n + 1));
    vector<ii> aux;
    for (int i = 1;i <= n;i++) {
      int x;
      cin >> x;
      for (int j = 0, m = 1;m <= x;j++, m <<= 1) {
        if (m & x) {
          msbi[i] = j;
          bs[j][i]++;
        }
      }
      aux.emplace_back(msbi[i], i);
    }
    sort(iter(aux));
    loop(30) {
      partial_sum(iter(bs[i]), bs[i].begin());
    }
    int last = -1;
    sort(iter(aux));
    vector<ll> o(n + 1), e(n + 1);
    ll ans = 0;
    for (auto& [m, p] : aux) {
      if (last != m) {
        fill(iter(o), 0);
        fill(iter(e), 0);
        loop(n + 1) {
          if (bs[m][i] & 1) o[i]++;
          else e[i]++;
        }
        partial_sum(iter(o), o.begin());
        partial_sum(iter(e), e.begin());
      }
      ans += o[p - 1] * (o[n] - o[p - 1]);
      ans += e[p - 1] * (e[n] - e[p - 1]);
      last = m;
    }
    cout << ans << endl;
  }
  return 0;
}

