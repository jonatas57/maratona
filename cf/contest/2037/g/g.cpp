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

const int N = 1000000;
vi lp(N + 1, 0), ps, mu(N + 1, 0);

void sieve() {
  mu[1] = 0;
  for (int i = 2;i <= N;i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      ps.push_back(i);
      mu[i] = -1;
    }
    each(p, ps) {
      if (p > lp[i] or i * p > N) break;
      lp[i * p] = p;
      mu[i * p] = i % p == 0 ? 0 : -mu[i];
    }
  }
}

vi getDivs(int x) {
  vi ds(1, 1);
  int lastp = -1;
  int lasts = 1;
  for (;x > 1;x /= lp[x]) {
    int l = 0, r = ds.size();
    if (lp[x] == lastp) l = lasts;
    lasts = ds.size();
    for (int i = l;i < r;i++) {
      ds.push_back(ds[i] * lp[x]);
    }
    lastp = lp[x];
  }
  return ds;
}

const int mod = 998244353;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  sieve();
  int n;
  cin >> n;
  vi a(n);
  loop(n) cin >> a[i];
  vector<ll> cnt(n);
  vector<ll> dcnt(1000001);
  cnt[n - 1] = 1;
  for (int i = n - 1;i >= 0;i--) {
    vi divs;
    getDivs(a[i]).swap(divs);
    each(x, divs) cnt[i] += dcnt[x] * (-mu[x]), cnt[i] %= mod;
    each(x, divs) dcnt[x] += cnt[i], dcnt[x] %= mod;
    cnt[i] = (cnt[i] + mod) % mod;
  }
  cout << cnt[0] << endl;
  return 0;
}

