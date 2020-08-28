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

  int t;
  cin >> t;
  for (int tc = 1;tc <= t;tc++) {
    string s;
    cin >> s;
    int ans = -1;
    int cnt = 0;
    bool left = false;
    char last = ' ';
    for (int i = 0;;i++) {
      char c = s[i];
      if (c == '<') {
        if (left) ans = max(ans, cnt + 1);
        cnt = 0;
        left = true;
      }
      else if (c == '>') {
        ans = max(ans, cnt + 1);
        cnt = 0;
        left = false;
      }
      else {
        if (c == last) cnt++;
        else {
          if (left) {
            ans = max(ans, cnt + 1);
          }
          cnt = 1;
          if (last == '-' or last == '=') left = false;
        }
      }
      if (!c) break;
      last = c;
    }
    cout << "Case " << tc << ": " << ans << endl;
  }
	return 0;
}

