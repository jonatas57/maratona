struct sufAuto {
  struct state {
    int id = 0, len = 0, link = -1;
    map<char, int> next;

    int& operator[](char c) {
      return next[c];
    }
  };
  
  vector<state> ss;
  int last;
  int size;

  sufAuto(string s) : ss(2 * s.length()), last(0), size(1) {
    each(c, s) {
      extend(c);
    }
  }

  state& newState(int len, int link = -1) {
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

  void extend(char c) {
    state& cur = newState(ss[last].len + 1);
    int p;
    for (p = last;p != -1 and !ss[p].next.count(c);p = ss[p].link) {
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
    last = cur.id;
  }

  state& operator[](int i) {
    return ss[i];
  }
};

