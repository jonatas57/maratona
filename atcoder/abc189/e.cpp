#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
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

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
  int l = a.size(), c = b[0].size(), x = a[0].size();
  vector<vector<ll>> ans(l, vector<ll>(c, 0));
  loop(l) {
    vloop(j, c) {
      vloop(k, x) {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vector<vector<vector<ll>>> ps;
  loop(n) {
    ll x, y;
    cin >> x >> y;
    ps.push_back({{x}, {y}, {1}});
  }
  int m;
  cin >> m;
  vector<vector<vector<ll>>> ops;
  loop(m) {
    int x;
    cin >> x;
    if (x == 1) ops.push_back({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
    else if (x == 2) ops.push_back({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});
    else {
      ll p;
      cin >> p;
      if (x == 3) ops.push_back({{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}});
      else ops.push_back({{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}});
    }
  }
  int q;
  cin >> q;
  vector<tuple<int, int, int>> qs;
  loop(q) {
    int a, b;
    cin >> a >> b;
    qs.emplace_back(a, b - 1, i);
  }
  sort(iter(qs));
  vector<pair<ll, ll>> ans(q);
  int last = 0;
  vector<vector<ll>> T = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  for (auto& [a, b, id] : qs) {
    if (last != a) {
      for (int i = last;i < a;i++) {
        mul(ops[i], T).swap(T);
      }
    }
    vector<vector<ll>> p = mul(T, ps[b]);
    ans[id] = {p[0][0], p[1][0]};
    last = a;
  }
  for (auto& [x, y] : ans) cout << x << " " << y << endl;
  return 0;
}

