#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int main() {
  ios_base::sync_with_stdio(false);

  int a, b, c, m;
  cin >> a >> b >> c >> m;
  vi usb, ps;
  int v;
  string s;
  loop(m) {
    cin >> v >> s;
    if (s == "USB") usb.pb(v);
    else ps.pb(v);
  }
  sort(usb.begin(), usb.end());
  sort(ps.begin(), ps.end());
  int t = 0;
  ll val = 0;

  int x = min(a, (int)usb.size());
  vi both(usb.begin() + x, usb.end());
  t += x;
  loop(x) val += usb[i];

  x = min(b, (int)ps.size());
  both.insert(both.end(), ps.begin() + x, ps.end());
  t += x;
  loop(x) val += ps[i];

  sort(both.begin(), both.end());

  x = min(c, (int)both.size());
  t += x;
  loop(x) val += both[i];
  cout << t << " " << val << endl;
  return 0;
}
