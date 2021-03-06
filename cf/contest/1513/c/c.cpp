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
const int M = 2e5;

vector<ll> aux(M + 15);

void pre() {
  ll cnt = 1;
  vi a(10, 0), b(10, 0);
  a[0] = 1;
  for (int j = 1;j < M + 15;j++) {
    vloop(k, 9) {
      b[k + 1] += a[k];
      b[k + 1] %= mod;
    }
    cnt += a[9];
    vloop(k, 2) {
      b[k] += a[9];
      b[k] %= mod;
      cnt %= mod;
    }
    aux[j] = cnt;
    loop(10) {
      a[i] = b[i];
      b[i] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  pre();
  int t;
  cin >> t;
  loop(t) {
    string n;
    int m;
    cin >> n >> m;
    ll ans = 0;
    each(c, n) {
      ans += aux[m + c - '0'];
      ans %= mod;
    }
    cout << ans << endl;
  }
  return 0;
}

