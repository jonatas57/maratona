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

int getMex(set<int>& s) {
  int mex = 0;
  each(x, s) {
    if (mex == x) mex++;
    else return mex;
  }
  return mex;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    vector<vi> ans(n, vi(m, 0));
    if (m > 1) {
      int p = min(n, m - 1);
      loop(p) {
        vloop(j, m) {
          ans[i][j] = (j - i - 1 + m) % m;
        }
      }
      for (int i = p;i < n;i++) {
        vloop(j, m) ans[i][j] = ans[i - 1][j];
      }
    }
    vector<set<int>> cs(m);
    loop(n) vloop(j, m) {
      cs[j].insert(ans[i][j]);
    }
    set<int> all;
    each(s, cs) all.insert(getMex(s));
    int mex = getMex(all);
    cout << mex << endl;
    each(v, ans) {
      each(x, v) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}

