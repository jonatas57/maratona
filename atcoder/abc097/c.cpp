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
const double EPS = 1e-7;
const double PI = acos(-1);

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

  bool find(string& s, int& pos) {
    int at = 0;
    for (;s[pos];pos++) {
      if (ss[at].next.count(s[pos])) {
        at = ss[at][s[pos]];
      }
      else return true;
    }
    return false;
  }
};

vi ch;

int dfs(sufAuto& s, int u) {
  ch[u] = 1;
  for (auto& [c, v] : s.ss[u].next) {
    ch[u] += dfs(s, v);
  }
  return ch[u];
}

void countChildren(sufAuto& s) {
  ch.resize(s.size, 0);
  dfs(s, 0);
}

string ksubstr(sufAuto& sa, int k) {
  string s = "";
  int acc = 0;
  for (int at = 0;acc < k and !sa.ss[at].next.empty();) {
    for (auto& [c, x] : sa.ss[at].next) {
      if (ch[x] + acc >= k) {
        at = x;
        s += c;
        k--;
        break;
      }
      else acc += ch[x];
    }
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  int k;
  cin >> s >> k;
  sufAuto sa(s);
  countChildren(sa);
  cout << ksubstr(sa, k) << endl;
  return 0;
}

