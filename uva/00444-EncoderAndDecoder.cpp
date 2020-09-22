#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  while (getline(cin, s)) {
    string ans = "";/*@*/
    cerr << (int)s.back() << endl;/*@*/
    if (isdigit(s[0])) {
      int x = 0;
      for (int i = s.length() - 1;i >= 0;i--) {
        x *= 10;
        x += s[i] - '0';
        if (x > 30) {
          ans += (char)x;
          x = 0;
        }
      }
    }
    else {
      each(c, s) ans += to_string((int)c);
      ans = string(riter(ans));
    }
    cout << ans << endl;
  }
	return 0;
}

