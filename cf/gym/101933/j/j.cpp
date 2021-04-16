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

  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll z = (sqrt(1 + 8 * a) + 1) / 2, o = (sqrt(1 + 8 * d) + 1) / 2;
  vector<ii> chs(1, {z, o});
  if (!a) {
    chs.emplace_back(z - 1, o);
    if (!d) chs.emplace_back(z - 1, o - 1);
  }
  if (!d) chs.emplace_back(z, o - 1);
  string ans = "impossible";
  for (auto& [z, o] : chs) {
    if (z * o != b + c) continue;
    if (z * (z - 1) / 2 != a or o * (o - 1) / 2 != d) continue;
    string s = "";
    ll x = b;
    for (ll i = z, j = o;i or j;) {
      if (x >= j) {
        s += '0';
        i--;
        x -= j;
      }
      else {
        s += '1';
        j--;
      }
    }
    ans = s;
    break;
  }
  cout << ans << endl;
  return 0;
}

