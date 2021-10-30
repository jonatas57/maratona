struct segtree {
  int id;
  vi st;

  segtree(vi& v) : size(v.size), st(size * 2) {
    loop(size) st[size + i] = v[i];
    for (int i = size - 1;i > 0;i--) st[i] = join(st[i << 1], st[i << 1 | 1]);
  }

  int join(int a, int b) {
    return a + b;
  }
  
  int query(int l, int r) {
    int ans = 0;
    for (l += size, r += size + 1;l > r;l >>= 1, r >>= 1) {
      if (l & 1) ans = join(ans, st[l++]);
      if (r & 1) ans = join(ans, st[--r]);
    }
    return ans;
  }
};
