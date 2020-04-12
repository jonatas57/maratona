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

  int vert = 3, hor = 3;
  string s;
  cin >> s;
  each(c, s) {
    if (c == '0') {
      cout << vert << " " << 1 << endl;
      vert ^= 2;
    }
    else {
      cout << 1 << " " << hor << endl;
      hor ^= 2;
    }
  }
	return 0;
}
