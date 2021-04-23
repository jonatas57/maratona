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
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    priority_queue<tuple<ll, int, int>> q;
    vector<vi> a(n, vi(m));
    loop(n) {
      vloop(j, m) {
        cin >> a[i][j];
      }
      sort(iter(a[i]));
      vloop(j, m) {
        q.emplace(-a[i][j], i, j);
      }
    }
    vector<vi> used(n, vi(m, 0));
    loop(m) {
      auto [z, x, y] = q.top();
      q.pop();/*@*/
      cerr << x << " " << y << endl;/*@*/
      used[x][y] = 1;
    }
    vector<vi> ans(n, vi(m, 0)), lr(n, {0, m - 1});
    loop(m) {
      bool ok = false;
      vloop(j, n) {
        if (used[j][lr[j][0]] == 1 and !ok) {
          ok = true;/*@*/
          cerr << "ok for " << i << endl;/*@*/
          ans[j][i] = a[j][lr[j][0]];
          used[j][lr[j][0]++] = 2;
        }
        else {
          ans[j][i] = a[j][lr[j][1]];
          used[j][lr[j][1]--] = 2;
        }
      }
    }
    each(v, ans) {
      each(x, v) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}

