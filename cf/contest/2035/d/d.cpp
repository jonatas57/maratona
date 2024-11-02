#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

const ll mod = 1000000007;

ll xp(ll b, ll e) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<ll> a(n), ans;
    vector<pair<ll, int>> st;
    loop(n) cin >> a[i];
    ll sum = 0;
    each(x, a) {
      int p = 0;
      while (x % 2 == 0) {
        p++;
        x >>= 1;
      }
      int acc = 0, cnt = 0;
      ll x2 = x;
      for (int i = st.size() - 1;i >= 0;i--) {
        auto [b, e] = st[i];
        while (x2 < b) x2 <<= 1, cnt++;
        if (cnt <= p + acc) {
          while (st.size() > i) {
            sum -= b * xp(2, e) % mod;
            sum += mod + b;
            sum %= mod;
            st.pop_back();
          }
          p += acc + e;
          acc = -e;
        }
        acc += e;
      }
      if (p) {
        st.emplace_back(x, p);
      }
      sum += x * xp(2, p) % mod;
      sum %= mod;
      ans.push_back(sum);
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

