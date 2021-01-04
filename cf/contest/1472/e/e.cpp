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

typedef tuple<int, int, int> tup;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<tup> sl;
    int h, w;
    loop(n) {
      cin >> h >> w;
      sl.emplace_back(h, w, i);
      sl.emplace_back(w, h, i);
    }
    sort(iter(sl));
    set<ii> ws;
    int lasth = -1;
    vector<ii> toins;
    vi ans(n, -1);
    for (auto& [h, w, id] : sl) {
      if (lasth != h) ws.insert(iter(toins)), toins.clear();
      if (ans[id] == -1) {
        each(p, ws) {
          if (p.second == id) continue;
          if (p.first < w) ans[id] = p.second + 1;
          break;
        }
      }
      toins.emplace_back(w, id);
      lasth = h;
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}


