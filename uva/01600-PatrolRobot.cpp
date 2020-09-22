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

vector<vi> mp(20, vi(20));

int bfs(int x, int y, int z) {
  vector<vector<vi>> dist(x, vector<vi>(y, vi(z + 1, -1)));
  vector<vector<vb>> visit(x, vector<vb>(y, vb(z + 1, false)));
  queue<tuple<int, int, int>> q;
  dist[0][0][z] = 0;
  visit[0][0][z] = true;
  q.emplace(0, 0, z);
  while (!q.empty()) {
    int i, j, k;
    tie(i, j, k) = q.front();
    q.pop();
    vloop(dir, 4) {
      int nx = i + (dir == 0) - (dir == 1);
      int ny = j + (dir == 2) - (dir == 3);
      if (nx < 0 or ny < 0 or nx >= x or ny >= y) continue;
      int nk = mp[nx][ny] ? k - 1 : z;
      if (nk < 0 or visit[nx][ny][nk]) continue;
      dist[nx][ny][nk] = dist[i][j][k] + 1;
      visit[nx][ny][nk] = true;
      q.emplace(nx, ny, mp[nx][ny] ? k - 1 : z);
    }
  }
  return dist[x - 1][y - 1][z];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int m, n, k;
    cin >> m >> n >> k;
    loop(m) vloop(j, n) cin >> mp[i][j];
    cout << bfs(m, n, k) << endl;
  }
	return 0;
}

