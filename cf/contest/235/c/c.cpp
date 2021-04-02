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
    vi linkch;

    int& operator[](char c) {
      return next[c];
    }
  };
  
  vector<state> ss;
  vi cnt;
  int last;
  int size;

  sufAuto(string s) : ss(2 * s.length()), cnt(2 * s.length(), 0), last(0), size(1) {
    each(c, s) {
      extend(c);
    }
    for (int i = 1;i < size;i++) ss[ss[i].link].linkch.push_back(i);
    processCnt();
  }

  state& newState(int len, int link = -1) {
    ss[size].id = size;
    ss[size].len = len;
    ss[size].link = link;
    cnt[size] = 1;
    size++;
    return ss[size - 1];
  }

  state& cloneState(state& s) {
    state& clone = newState(s.len, s.link);
    clone.next = s.next;
    cnt[clone.id] = 0;
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

  int countCyclic(string x) {
    int ans = 0;
    int l = x.length(), ls = 0;
    vb used(size, false);
    x += x;
    for (int at = 0, i = 0;x[i];i++) {
      if (ss[at].next.count(x[i])) {
        at = ss[at][x[i]];
        ls++;
        while (ss[at].link != -1 and ss[ss[at].link].len >= l) at = ss[at].link;
        ls = min(ls, ss[at].len);
        if (ls >= l and !used[at]) ans += cnt[at], used[at] = true;
      }
      else {
        while (ss[at].link != -1 and !ss[at].next.count(x[i])) at = ss[at].link;
        if (ss[at].next.count(x[i])) i--;
        ls = min(ls, ss[at].len);
      }
    }
    return ans;
  }

  int processCnt(int u = 0) {
    each(v, ss[u].linkch) {
      cnt[u] += processCnt(v);
    }
    return cnt[u];
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s, x;
  int n;
  cin >> s >> n;
  sufAuto sa(s);
  loop(n) {
    cin >> x;
    cout << sa.countCyclic(x) << endl;
  }
  return 0;
}

