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

set<ii> getPos(int x, int y, int a, int b) {
  set<ii> ans;
  ans.emplace(x + a, y + b);
  ans.emplace(x + a, y - b);
  ans.emplace(x - a, y + b);
  ans.emplace(x - a, y - b);
  ans.emplace(x + b, y + a);
  ans.emplace(x + b, y - a);
  ans.emplace(x - b, y + a);
  ans.emplace(x - b, y - a);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int a, b;
    cin >> a >> b;
    int xk, yk, xq, yq;
    cin >> xk >> yk >> xq >> yq;
    set<ii> s = getPos(xk, yk, a, b);
    set<ii> t = getPos(xq, yq, a, b);
    int ans = 0;
    each(p, t) {
      if (s.count(p)) ans++;
    }
    cout << ans << endl;
  }
  return 0;
}

