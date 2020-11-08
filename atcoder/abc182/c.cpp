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

  string n;
  cin >> n;
  vi cnt(3, 0);
  each(c, n) cnt[(c - '0') % 3]++;
  int m = (cnt[1] + cnt[2] * 2) % 3;
  int ans = 0;
  if (m) {
    if (cnt[m]) ans = 1;
    else if (cnt[m ^ 3] > 1) ans = 2;
    else ans = -1;
  }
  if (ans == (int)n.length()) ans = -1;
  cout << ans << endl;
  return 0;
}

