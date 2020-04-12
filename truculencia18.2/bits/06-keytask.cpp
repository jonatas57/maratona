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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int r, c;
vector<string> mapa(100);

map<char, int> aux = {{'B', 0}, {'Y', 1}, {'R', 2}, {'G', 3}};

int bfs(int x, int y) {
	vector<vector<vi>> dist(r, vector<vi>(c, vi(16, INF)));
	vector<vector<vb>> visit(r, vector<vb>(c, vb(16, false)));
	queue<tuple<int, int, int>> q;
	dist[x][y][0] = 0;
	visit[x][y][0] = true;
	q.emplace(x, y, 0);
	int k;
	while (!q.empty()) {
		tie(x, y, k) = q.front();
		q.pop();
		vloop(dir, 4) {
			int nx = x + (dir == 2) - (dir == 0);
			int ny = y + (dir == 1) - (dir == 3);
			int nk = k;
			if (nx < 0 or nx >= r or ny < 0 or ny >= c or visit[nx][ny][nk] or mapa[nx][ny] == '#') continue;
			if (islower(mapa[nx][ny])) {
				nk |= 1 << (aux[toupper(mapa[nx][ny])]);
			}
			else if (isupper(mapa[nx][ny])) {
				if (mapa[nx][ny] == 'X') return dist[x][y][k] + 1;
				int x = nk & (1 << aux[mapa[nx][ny]]);
				if (!x) continue;
			}
			visit[nx][ny][nk] = true;
			dist[nx][ny][nk] = dist[x][y][k] + 1;
			q.emplace(nx, ny, nk);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	while (cin >> r >> c and r | c) {
		int x, y;
		loop(r) {
			cin >> mapa[i];
			vloop(j, c) if (mapa[i][j] == '*') x = i, y = j;
		}
		int ans = bfs(x, y);
		if (ans == -1) cout << "The poor student is trapped!" << endl;
		else cout << "Escape possible in " << ans << " steps." << endl;
	}
	return 0;
}

