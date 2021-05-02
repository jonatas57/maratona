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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, l, r;
    cin >> n >> l >> r;
    vi cs(n), cnt(n + 1, 0);
    vector<vi> ss(n + 1);
    int cost = 0;
    loop(n) {
      cin >> cs[i];
      ss[cs[i]].push_back(i < l ? -1 : 1);
      cnt[cs[i]]++;
      if (cnt[cs[i]] >= 2) {
        if (ss[cs[i]][cnt[cs[i]] - 1] != ss[cs[i]][cnt[cs[i]] - 2]) {
          vloop(j, 2) ss[cs[i]].pop_back();
          cnt[cs[i]] -= 2;
        }
      }
    }
    int cntl = 0, cntr = 0;
    int pl = 0, pr = 0;
    for (int c = 1;c <= n;c++) {
      if (!cnt[c]) continue;
      if (ss[c][0] == -1) pl += cnt[c] / 2;
      else pr += cnt[c] / 2;
      cnt[c] = cnt[c] & 1;
      ss[c].resize(cnt[c]);
      if (cnt[c]) {
        ss[c][0] == -1 ? cntl++ : cntr++;
      }
    }
    cost += pl + pr;
    if (cntl > cntr) swap(pl, pr), swap(cntl, cntr);
    cost += cntl;
    int x = abs(cntr - cntl);
    while (pl and x) {
      pl--;
      x -= 2;
      cost++;
    }
    cost += x;
    cout << cost << endl;
  }
  return 0;
}

