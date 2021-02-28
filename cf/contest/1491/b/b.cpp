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
    ll n, u, v;
    cin >> n >> u >> v;
    ll m = min(u, v);
    vi a(n);
    vb on(n + 1, false);
    on[0] = on[n] = true;
    ll ans = 0;
    int ul = 0, rd = n - 1;
    loop(n) {
      cin >> a[i];
      if (i) {
        on[i] = abs(a[i] - a[i - 1]) <= 1;
      }
    }
    while (ul < n and on[ul] and a[ul]) ul++;
    while (rd >= 0 and on[rd + 1] and a[rd] != 1000001) rd++;
    if (a[ul] == 0 or ul == n) {
      ll aux = INFLL;
      for (int i = 1;i < ul - 1;i++) {
        ll cost = m;
        if (a[i] == a[i - 1] and a[i] == a[i + 1]) cost += v;
        aux = min(aux, cost);
      }
      if (a[0] == a[1]) aux = min(aux, m + v);
      else if (a[0] == 1 and a[1] == 2) aux = min({aux, u, v + v + m});
      else aux = min(aux, m);
      if (ul == n) {
        ul--;
        if (a[ul] == a[ul - 1]) aux = min(aux, m + v);
        else if (a[ul] == 1000000 and a[ul - 1] == 999999) aux = min({aux, u, v + v + m});
        else aux = min(aux, m);
      }
      else {
        if (a[ul] == a[ul + 1]) aux = min(aux, v + m);
        else aux = min({aux, v + v + m, u});
      }
      ans += aux;
    }
    if (rd > 0 and a[rd] == 1000001) {
      ll aux = INFLL;
      for (int i = n - 1;i >= rd;i--) {
        ll cost = m;
        if (a[i] == a[i - 1] and a[i] == a[i + 1]) cost += v;
        aux = min(aux, cost);
      }
      if (a[n - 1] == a[n - 2]) aux = min(aux, m + v);
      else if (a[n - 1] == 1000000 and a[n - 2] == 999999) aux = min({aux, u, v + v + m});
      else aux = min(aux, m);
      if (a[rd] == a[rd - 1]) aux = min(aux, v + m);
      else aux = min({aux, v + v + m, u});
      ans += aux;
    }
    cout << ans << endl;
  }
  return 0;
}

