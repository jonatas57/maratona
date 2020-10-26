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

const int N = 3e5 + 1, T = 4 * N + 10;
vector<ii> st(T, {0, -1});

void update(int id, int l, int r, int pos, ii d) {
  if (l == r) st[id] = d;
  else {
    int mid = avg(l, r);
    if (pos <= mid) update(id << 1, l, mid, pos, d);
    if (pos > mid) update(id << 1 | 1, mid + 1, r, pos, d);
    st[id] = max(st[id << 1], st[id << 1 | 1]);
  }
}

ii query(int id, int l, int r, int a, int b) {
  if (r < a or l > b) return {0, -1};
  if (a <= l and r <= b) return st[id];
  int mid = avg(l, r);
  return max(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  int x;
  loop(n) {
    cin >> x;
    auto [len, pos] = query(1, 0, N - 1, x - k, x + k);
    update(1, 0, N - 1, x, {len + 1, i});
  }
  cout << query(1, 0, N - 1, 0, N - 1).first << endl;
  return 0;
}

