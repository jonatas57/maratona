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

  string s;
  cin >> s;
  string t = "";
  each(c, s) if (c != 'a') t += c;
  bool p;
  int l = t.length();
  if (l & 1 || t.substr(0, l / 2) != t.substr(l / 2)) {
    p = false;
  }
  else if (l == 0) p = true;
  else {
    l /= 2;
    int ls = s.length();
    t = t.substr(l);
    int x = s.find(t);
    while (x != ls - l && x != string::npos) {
      x = s.find(t, x + 1);
    }
    if ((p = (x == ls - l))) {
      s = s.substr(0, ls - l);
    }
  }
  cout << (p ? s : ":(") << endl;
  return 0;
}
