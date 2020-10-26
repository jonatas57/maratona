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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<ii> ps;
    for (int i = 0, j = 0;;) {
      if (s[j] == 'W') {
        j++;
      }
      else {
        if (i < j) {
          ps.emplace_back(i, j - i);
        }
        if (!s[j]) break;
        j++;
        i = j;
      }
    }
    vector<ii> ss;
    loop((int)ps.size() - 1) {
      int d = ps[i + 1].first - ps[i].first - ps[i].second;
      ss.emplace_back(d, ps[i].first + ps[i].second);
    }
    sort(iter(ss));
    for (auto& [dist, id] : ss) {
      if (dist <= k) {
        loop(dist) {
          if (!k) break;
          s[i + id] = 'W';
          k--;
        }
      }
    }
    if (k) {
      if (ps.size()) {
        for (int i = 1;s[i] and k;i++) {
          if (s[i] == 'L' and s[i - 1] == 'W') {
            s[i] = 'W';
            k--;
          }
        }
        for (int i = n - 1;i >= 0 and k;i--) {
          if (s[i] == 'L' and s[i + 1] == 'W') {
            s[i] = 'W';
            k--;
          }
        }
      }
      else {
        for (int i = 0;s[i] and k;i++) {
          s[i] = 'W';
          k--;
        }
      }
    }
    int ans = 0;
    char l = '0';
    each(c, s) {
      if (c == 'W') ans += 1 + (c == l);
      l = c;
    }
    cout << ans << endl;
  }
  return 0;
}
