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
  vi st;

  segtree(int n, int val = 0) : size(n), st(4 * n + 10, val) {}

  void update(int id, int l, int r, int pos, int val) {
    if (l > pos or r < pos) return;
    if (l == r) st[id] = val;
    else {
      int mid = avg(l, r);
      if (pos <= mid) update(id << 1, l, mid, pos, val);
      else update(id << 1 | 1, mid + 1, r, pos, val);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }

  int query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return INF;
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return min(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  void update(int pos, int val) {
    update(1, 0, size - 1, pos, val);
  }
  int query(int l, int r) {
    int x = query(1, 0, size - 1, l, r);
    return x == INF ? -1 : x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int k;
  string s;
  cin >> k >> s;
  int n = s.length();
  map<char, int> cnt;
  int x = 0;
  vi ans(n, 0);
  segtree st(n, INF);
  vector<list<int>> pos(26);
  for (int i = 0, j = 0;j < n;j++) {
    if (!cnt[s[j]]++) x++;
    pos[s[j] - 'a'].push_back(j);
    while (x > k) {
      pos[s[i] - 'a'].pop_front();
      if (!(--cnt[s[i++]])) x--;
    }
    if (x == k) {
      int r = INF;
      each(v, pos) if (!v.empty()) r = min(r, v.back());
      ans[j] = (i ? st.query(i - 1, r - 1) : 0) + 1;
      st.update(j, ans[j]);
    }
    if (!ans[j]) {
      ans[j] = -1;
      st.update(j, INF);
    }
  }
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

