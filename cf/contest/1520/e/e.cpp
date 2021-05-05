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

ll calc(vi& s, int x) {
  if (s.empty()) return 0;
  ll ans = 0;
  int p = 0;
  each(y, s) {
    ans += abs(s[x] - y) - abs(x - p);
    p++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    string s;
    cin >> n >> s;
    vi ss;
    loop(n) {
      if (s[i] == '*') ss.push_back(i);
    }
    int m = ss.size();
    ll ans = calc(ss, m / 2);
    if (~m & 1) ans = min(ans, calc(ss, m / 2 + 1));
    cout << ans << endl;
  }
  return 0;
}

