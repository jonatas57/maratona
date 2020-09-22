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

struct segtree {
  int size;
  vi st, lazy;
  segtree(vi& v) : size(v.size()), st(4 * size + 10), lazy(4 * size + 10) {
    build(v, 1, 0, size - 1);
  }
  void build(vi& v, int id, int l, int r) {
    if (l == r) st[id] = v[l];
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }
  void prop(int id, int l, int r) {
    if (lazy[id]) {
      st[id] += lazy[id];
      if (l != r) {
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
      }
      lazy[id] = 0;
    }
  }
  void update(int id, int l, int r, int a, int b) {
    prop(id, l, r);
    if (l > b or r < a) return;
    if (a <= l and r <= b) {
      lazy[id]--;
      prop(id, l, r);
    }
    else {
      int mid = avg(l, r);
      update(id << 1, l, mid, a, b);
      update(id << 1 | 1, mid + 1, r, a, b);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }
  void update(int l, int r) {
    update(1, 0, size - 1, l, r);
  }
  void checkZeroes(int id, int l, int r, vi& ans, int val) {
    prop(id, l, r);
    if (st[id]) return;
    if (l == r) ans[l] = val, st[id] = INF;
    else {
      int mid = avg(l, r);
      checkZeroes(id << 1, l, mid, ans, val);
      checkZeroes(id << 1 | 1, mid + 1, r, ans, val);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }
  void checkZeroes(vi& ans, int val) {
    checkZeroes(1, 0, size - 1, ans, val);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vi a(n);
  loop(n) a[i] = i + 1;
  segtree st(a);
  int l, r;
  vi ans(n, -1);
  loop(n) {
    cin >> l >> r;
    st.update(l - 1, r - 1);
    st.checkZeroes(ans, i + 1);
  }
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

