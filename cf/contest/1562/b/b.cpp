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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  vi xs = {1, 4, 6, 8, 9};
  loop(t) {
    int n;
    string s;
    cin >> n >> s;
    vi cnt(10, 0);
    int ans = 0, d = 0;
    each(c, s) cnt[c - '0']++;
    each(x, xs) {
      if (cnt[x]) {
        ans = x;
        d = 1;
      }
    }
    if (!ans) {
      map<char, ii> pos;
      loop(n) {
        if (!pos.count(s[i])) pos[s[i]] = {INF, -1};
        auto& [l, r] = pos[s[i]];
        l = min(l, i);
        r = max(r, i);
      }
      for (auto a : "2357") {
        if (ans) break;
        if (!pos.count(a)) continue;
        for (auto b : "2357") {
          if (!pos.count(b)) continue;
          string s = "";
          s += a;
          s += b;
          if (s == "23" or s == "37" or s == "53" or s == "73") continue;
          if (pos[a].first < pos[b].second) {
            ans = 10 * (a - '0') + b - '0';
            d = 2;
            break;
          }
        }
      }
    }
    cout << d << endl << ans << endl;
  }
  return 0;
}

