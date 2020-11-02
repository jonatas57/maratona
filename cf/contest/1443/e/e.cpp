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

vector<ll> fat(15, 1);
vi permutation(int n, ll k) {
  vi p;
  vi aux = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
  loop(n) {
    ll x = k / fat[n - i - 1];
    p.push_back(aux[x]);
    aux.erase(aux.begin() + x);
    k %= fat[n - i - 1];
  }
  return p;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  for (int i = 1;i <= 14;i++) fat[i] = fat[i - 1] * i;

  int n, q;
  cin >> n >> q;
  ll m = max(0, n - 14);
  ll p = 0, last = -1;
  vector<ll> acc(n - m + 1, 0);
  loop(q) {
    ll op, l, r;
    cin >> op >> l;
    if (op == 1) {
      cin >> r;
      l--, r--;
      ll ans = 0;
      ll x = max(l, m), y = min(r, m - 1);
      if (last < p) {
        vi perm = permutation(n - m, p);
        loop(n - m) acc[i + 1] = acc[i] + perm[i] + m;
        last = p;
      }
      if (l < m) {
        ans += ((y + 2) * (y + 1) - l * (l + 1)) / 2;
      }
      if (r >= m) {
        ans += acc[r - m + 1] - acc[x - m];
      }
      cout << ans << endl;
    }
    else {
      p += l;
    }
  }
  return 0;
}

