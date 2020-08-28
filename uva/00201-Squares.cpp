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

  int n, m;
  for (int i = 0;cin >> n >> m;i++) {
    if (i) cout << endl << "**********************************" << endl << endl;
    vector<vector<vb>> adj(n + 5, vector<vb>(n + 5, vb(4, false)));
    char c;
    int a, b;
    loop(m) {
      cin >> c >> a >> b;
      a--, b--;
      if (c == 'V') swap(a, b);
      int na = a + (c == 'V');
      int nb = b + (c == 'H');
      adj[a][b][c == 'H' ? 0 : 1] = adj[na][nb][c == 'H' ? 2 : 3] = true;
    }
    mii cnt;
    for (int s = 1;s <= n;s++) {
      for (int i = 0;i < n - s;i++) {
        for (int j = 0;j < n - s;j++) {
          bool ok = true;
          int x = i, y = j;
          for (int dir = 0;ok and dir < 4;dir++) {
            for (int st = 0;ok and st < s;st++) {
              if (!adj[x][y][dir]) ok = false;
              x += (dir == 1) - (dir == 3);
              y += (dir == 0) - (dir == 2);
            }
          }
          if (ok) cnt[s]++;
        }
      }
    }
    cout << "Problem #" << i + 1 << endl << endl;
    bool ok = false;
    each(p, cnt) {
      ok = true;
      cout << p.second << " square (s) of size " << p.first << endl;
    }
    if (!ok) cout << "No completed squares can be found." << endl;
  }
	return 0;
}

