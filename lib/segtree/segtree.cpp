struct segtree {
  int size;
  vi st;

  int join(int a, int b) {
    return min(a, b);
  }

  segtree(int n) : size(n), st(4 * n + 10) {}
  segtree(vi& v) : segtree(v.size()) {
    build(v, 1, 0, size - 1);
  }

  void build(vi& v, int id, int l, int r) {
    if (l == r) st[id] = v[l];
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  void update(int id, int l, int r, int pos, int val) {
    if (l == r) st[id] = val;
    else {
      int mid = avg(l, r);
      if (pos <= mid) update(id << 1, l, mid, pos, val);
      else            update(id << 1 | 1, mid + 1, r, pos, val);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  int query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return INF;
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return join(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  void update(int pos, int val) {
    update(1, 0, size - 1, pos, val);
  }

  int query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};

