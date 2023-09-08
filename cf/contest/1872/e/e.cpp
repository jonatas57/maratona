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

ii flip(ii p) {
  return make_pair(p.second, p.first);
}

struct segtree {
  int size;
  vector<ii> st;
  vb lazy;
  ii empty = {0, 0};

  ii join(ii a, ii b) {
    return make_pair(a.first xor b.first, a.second xor b.second);
  }

  segtree(int n) : size(n), st(4 * n + 10), lazy(4 * n + 10) {}
  segtree(vi& v, string& s) : segtree(v.size()) {
    build(v, s, 1, 0, size - 1);
  }

  void build(vi& v, string& s, int id, int l, int r) {
    if (l == r) st[id] = s[l] == '0' ? make_pair(v[l], 0) : make_pair(0, v[l]);
    else {
      int mid = avg(l, r);
      build(v, s, id << 1, l, mid);
      build(v, s, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  void prop(int id, int l, int r) {
    if (lazy[id]) {
      st[id] = flip(st[id]);
      if (l < r) {
        lazy[id << 1] = lazy[id << 1] xor lazy[id];
        lazy[id << 1 | 1] = lazy[id << 1 | 1] xor lazy[id];
      }
      lazy[id] = 0;
    }
  }

  void update(int id, int l, int r, int a, int b) {
    prop(id, l, r);
    if (l > b or r < a) return;
    if (a <= l and r <= b) {
      lazy[id] = 1;
      prop(id, l, r);
    }
    else {
      int mid = avg(l, r);
      update(id << 1, l, mid, a, b);
      update(id << 1 | 1, mid + 1, r, a, b);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  ii query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return empty;
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return join(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  void update(int l, int r) {
    update(1, 0, size - 1, l, r);
  }

  int query(int v) {
    ii a = query(1, 0, size - 1, 0, size - 1);
    return v ? a.second : a.first;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    loop(n) cin >> a[i];
    string s;
    cin >> s;
    segtree st(a, s);
    int q;
    cin >> q;
    loop(q) {
      int op, a, b;
      cin >> op >> a;
      if (op == 1) {
        cin >> b;
        st.update(a - 1, b - 1);
      }
      else {
        cout << st.query(a) << " ";
      }
    }
    cout << endl;
  }
  return 0;
}

