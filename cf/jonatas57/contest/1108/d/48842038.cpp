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

#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

  mii change = {{'R', 'G'}, {'G', 'B'}, {'B', 'R'}};

  int n;
  string s;
  cin >> n >> s;

  int r = 0;
  rep(1, n, 1) {
    if ((i < n - 1 && s[i] == s[i + 1] && s[i] == s[i - 1]) || (i == n - 1 && s[i] == s[i - 1])) {
      s[i] = change[s[i]];
      r++;
    }
    else if (s[i] == s[i - 1]) {
      s[i] = 'R' + 'G' + 'B' - s[i - 1] - s[i + 1];
      r++;
    }
  }
  cout << r << endl << s << endl;
	return 0;
}
