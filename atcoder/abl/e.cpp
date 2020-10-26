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

const ll mod = 998244353;

const int N = 2e5, T = 4 * N + 10;
vector<ll> st(T), lazy(T), pw(N, 1), accpw(N + 1, 1);

void build(int id, int l, int r) {
  if (l == r) st[id] = 1;
  else {
    int mid = avg(l, r);
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = ((st[id << 1] * pw[r - mid]) % mod + st[id << 1 | 1]) % mod;
  }
};

void prop(int id, int l, int r) {
  if (lazy[id]) {
    st[id] = lazy[id] * accpw[r - l] % mod;
    if (l != r) {
      lazy[id << 1] = lazy[id];
      lazy[id << 1 | 1] = lazy[id];
    }
    lazy[id] = 0;
  }
}

void update(int id, int l, int r, int a, int b, int d) {
  prop(id, l, r);
  if (r < a or l > b) return;
  if (a <= l and r <= b) lazy[id] = d, prop(id, l, r);
  else {
    int mid = avg(l, r);
    update(id << 1, l, mid, a, b, d);
    update(id << 1 | 1, mid + 1, r, a, b, d);
    st[id] = ((st[id << 1] * pw[r - mid]) % mod + st[id << 1 | 1]) % mod;
  }
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  for (int i = 1;i <= n;i++) {
    pw[i] = pw[i - 1] * 10 % mod;
    accpw[i] = (accpw[i - 1] + pw[i]) % mod;
  }
  build(1, 0, n - 1);
  int l, r, d;
  loop(q) {
    cin >> l >> r >> d;
    update(1, 0, n - 1, l - 1, r - 1, d);
    cout << st[1] << endl;
  }
  return 0;
}

