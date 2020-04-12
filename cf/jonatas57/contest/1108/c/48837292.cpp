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

  int n;
  string s;
  vector<string> t = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
  cin >> n >> s;
  vi dists(6, 0);
  loop(6) {
    for (int j = 0, k = 0;j < n;j++, k = (k + 1) % 3) {
      if (s[j] != t[i][k]) {
        dists[i]++;
      }
    }
  }
  int mind = n + 1, id;
  loop(6) {
    if (mind > dists[i]) {
      mind = dists[i];
      id = i;
    }
  }
  for (int i = 0, j = 0;i < n;i++, j = (j + 1) % 3) {
    s[i] = t[id][j];
  }
  cout << mind << endl << s << endl;
	return 0;
}
