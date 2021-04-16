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

const int N = 5e4, T = 4 * N + 10;
vi st(T);
void build(vi& v, int id, int l, int r) {
  if (l == r) st[id] = v[l];
  else {
    int mid = avg(l, r);
    build(v, id << 1, l, mid);
    build(v, id << 1 | 1, mid + 1, r);
    st[id] = gcd(st[id << 1], st[id << 1 | 1]);
  }
}

int query(int id, int l, int r, int a, int b) {
  if (l > b or r < a) return 0;
  if (a <= l and r <= b) return st[id];
  int mid = avg(l, r);
  return gcd(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  vi a(n);
  loop(n) cin >> a[i];
  build(a, 1, 0, n - 1);
  loop(q) {
    int l, r;
    cin >> l >> r;
    cout << (query(1, 0, n - 1, l - 1, r - 1) == 1 ? "S" : "N") << endl;
  }
  return 0;
}

