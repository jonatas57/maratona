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

int n, m;

vector<string> maze(50);

bool valid(int x, int y) {
	return x >= 0 and y >= 0 and x < n and y < m;
}

vector<vb> visit;
void block(int x, int y) {
	visit[x][y] = true;
	vloop(dir, 4) {
		int nx = x + (dir == 2) - (dir == 0);
		int ny = y + (dir == 1) - (dir == 3);
		if (valid(nx, ny) and !visit[nx][ny]) {
			if (maze[nx][ny] == '.') {
				maze[nx][ny] = '#';
			}
			else if (maze[nx][ny] != '#') {
				block(nx, ny);
			}
		}
	}
}

int bfs() {
	if (maze[n - 1][m - 1] == '#') return 0;
	vector<vb> visit(n, vb(m, false));
	queue<ii> q;
	int g = 0;
	q.emplace(n - 1, m - 1);
	visit[n - 1][m - 1] = true;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		vloop(dir, 4) {
			int nx = x + (dir == 2) - (dir == 0);
			int ny = y + (dir == 1) - (dir == 3);
			if (valid(nx, ny) and maze[nx][ny] != '#' and !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.emplace(nx, ny);
				if (maze[nx][ny] == 'G') g++;
			}
		}
	}
	return g;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> n >> m;
		loop(n) cin >> maze[i];
		int g = 0;
		visit.assign(n, vb(m, false));
		loop(n) vloop(j, m) {
			if (maze[i][j] == 'G') g++;
			else if (maze[i][j] == 'B') block(i, j);
		}
		cout << (g == bfs() ? "Yes" : "No") << endl;
	}
	return 0;
}

