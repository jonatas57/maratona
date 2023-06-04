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

struct bstring {
  int n;
  string s;
  set<int> ls, rs;
  bstring(string s) : n(s.length()), s(s) {
    loop((int)s.length() - 1) {
      if (s[i] == s[i + 1]) {
        if (s[i] == '(') ls.insert(i);
        else rs.insert(i);
      }
    }
  }

  bool flip(int p) {
    if (s[p] == '(') {
      s[p] = ')';
      ls.erase(p);
      ls.erase(p - 1);
      if (p and s[p - 1] == ')') rs.insert(p - 1);
      if (p < n and s[p + 1] == ')') rs.insert(p);
    }
    else {
      s[p] = '(';
      rs.erase(p);
      rs.erase(p - 1);
      if (p and s[p - 1] == '(') ls.insert(p - 1);
      if (p < n and s[p + 1] == '(') ls.insert(p);
    }
    return rs.empty() or (!ls.empty() and *ls.begin() < *rs.begin());
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  string s, t;
  cin >> n >> q >> s;
  for (int i = n - 1;i >= 0;i--) {
    t += s[i] xor '(' xor ')';
  }
  bstring a(s), b(t);
  loop(q) {
    int x;
    cin >> x;
    x--;
    if (n & 1) {
      cout << "NO" << endl;
      continue;
    }
    bool p = a.flip(x);
    bool q = b.flip(n - 1 - x);
    cout << (p and q and a.s[0] == '(' and b.s[0] == '(' ? "YES" : "NO") << endl;
  }
  return 0;
}

