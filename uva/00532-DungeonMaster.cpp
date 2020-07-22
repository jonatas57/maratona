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

int l, r, c;
vector<vector<string>> d;

int bfs(int x, int y, int z) {
	vector<vector<vi>> dist(l, vector<vi>(r, vi(c, INF)));
	queue<tuple<int, int, int>> q;
	dist[x][y][z] = 0;
	q.emplace(x, y, z);
	while (!q.empty()) {
		tie(x, y, z) = q.front();
		q.pop();
		vloop(dir, 6) {
			int nx = x + (dir == 0) - (dir == 1);
			int ny = y + (dir == 2) - (dir == 3);
			int nz = z + (dir == 4) - (dir == 5);
			if (nx < 0 or nx >= l or ny < 0 or ny >= r or nz < 0 or nz >= c or d[nx][ny][nz] == '#' or dist[nx][ny][nz] != INF) continue;
			dist[nx][ny][nz] = dist[x][y][z] + 1;
			if (d[nx][ny][nz] == 'E') return dist[nx][ny][nz];
			q.emplace(nx, ny, nz);
		}
	}
	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	while (cin >> l >> r >> c and l | r | c) {
		d.assign(l, vector<string>(r));
		int x, y, z;
		loop(l) vloop(j, r) {
			cin >> d[i][j];
			vloop(k, c) if (d[i][j][k] == 'S') x = i, y = j, z = k;
		}
		int ans = bfs(x, y, z);
		if (ans == INF) cout << "Trapped!" << endl;
		else cout << "Escaped in " << ans << " minute(s)." << endl;
	}
	return 0;
}

