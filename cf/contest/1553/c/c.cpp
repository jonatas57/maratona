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

int solve(string& s, int pos = 0, int p = 0, int a = 0, int b = 0, int ma = 5, int mb = 5) {
  if (!s[pos]) return 10;
  char c = s[pos];
  int ans = INF;
  for (char d = '0';d <= '1';d++) {
    int x = a, y = b, w = ma, z = mb;
    if (c == '?' or c == d) {
      if (d == '0') p ? z-- : w--;
      else p ? y++ : x++;
      if (z < x or w < y) return pos + 1;
      ans = min(ans, solve(s, pos + 1, !p, x, y, w, z));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    string s;
    cin >> s;
    cout << solve(s) << endl;
  }
  return 0;
}

