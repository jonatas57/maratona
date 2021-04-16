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

struct trie {
  int size;
  vb isend;
  vi cnt;
  vector<map<char, int>> next;
  trie() : size(1), isend(1, false), cnt(1, 0), next(1) {}
  void addString(string s) {
    int at = 0;
    cnt[0]++;
    each(c, s) {
      if (!next[at].count(c)) {
        isend.emplace_back(false);
        cnt.emplace_back(0);
        next.emplace_back();
        next[at][c] = size++;
      }
      at = next[at][c];
      cnt[at]++;
    }
    isend[at] = true;
  }
  
  int solve(string s, int pos) {
    int ans = s.length() + 1, at = 0, pre = 0, qtd = cnt[0];
    each(c, s) {
      int l = isend[at], r = 0;
      for (char d = 'a';d <= 'z';d++) {
        if (d == c) continue;
        if (next[at].count(d)) {
          if (d < c) l += cnt[next[at][d]];
          else r += cnt[next[at][d]];
        }
      }
      ans = min(ans, pre + 1 + min(pos, qtd - pos));
      pre++;
      pos -= l;
      at = next[at][c];
      qtd = cnt[at];
    }
    return ans;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<pair<string, int>> ss;
    trie t;
    loop(n) {
      string s;
      cin >> s;
      ss.emplace_back(s, i);
      t.addString(s);
    }
    sort(iter(ss));
    vi ans(n);
    loop(n) {
      ans[ss[i].second] = t.solve(ss[i].first, i);
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

