struct sufAuto {
  struct state {
    int id = 0, len = 0, link = -1;
    bool end = false;
    map<char, int> next;

    int& operator[](char c) {
      return next[c];
    }
  };
  
  vector<state> ss;
  int size;

  sufAuto() : ss(1), size(1) {}

  void addString(string& s) {
    int at = 0;
    each(c, s) {
      at = extend(at, c);
    }
    for (int i = at;ss[i].link != -1;i = ss[i].link) ss[i].end = true;
  }

  state& newState(int len, int link = -1) {
    ss.emplace_back();
    ss[size].id = size;
    ss[size].len = len;
    ss[size].link = link;
    size++;
    return ss[size - 1];
  }

  state& cloneState(state& s) {
    state& clone = newState(s.len, s.link);
    clone.next = s.next;
    return clone;
  }

  int extend(int at, char c) {
    state& cur = newState(ss[at].len + 1);
    int p;
    for (p = at;p != -1 and !ss[p].next.count(c);p = ss[p].link) {
      ss[p][c] = cur.id;
    }
    if (p == -1) {
      cur.link = 0;
    }
    else {
      int q = ss[p][c];
      if (ss[p].len + 1 == ss[q].len) {
        cur.link = q;
      }
      else {
        state& clone = cloneState(ss[q]);
        clone.len = ss[p].len + 1;
        while (p != -1 and ss[p][c] == q) {
          ss[p][c] = clone.id;
          p = ss[p].link;
        }
        cur.link = ss[q].link = clone.id;
      }
    }
    return cur.id;
  }

  void printAcc(int u = 0, string s = "") {
    if (ss[u].end) cerr << s << endl;
    for (auto& [c, x] : ss[u].next) {
      printAcc(x, s + c);
    }
  }

  state& operator[](int i) {
    return ss[i];
  }
};

