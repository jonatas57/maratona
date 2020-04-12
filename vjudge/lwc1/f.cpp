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
const int N = 1000;

int r, c;

int g[N][N];
int dist[N][N];
int visit[N][N];

vi dx = {-1, -1, 0, 1, 1, 1, 0, -1}, dy = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int a, int b) {
	memset(dist, INF, sizeof(dist));
	memset(visit, 0, sizeof(visit));
	deque<ii> q;
	q.emplace_back(a, b);
	dist[a][b] = 0;
	int x, y;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop_front();
		if (visit[x][y]) continue;
		visit[x][y] = 1;
		loop(8) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int w = i != g[x][y];
			if (nx < 0 or nx >= r or ny < 0 or ny >= c or dist[nx][ny] <= dist[x][y] + w) continue;
			dist[nx][ny] = dist[x][y] + w;
			w ? q.emplace_back(nx, ny) : q.emplace_front(nx, ny);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	scanf("%d %d\n", &r, &c);
	loop(r) {
		vloop(j, c) {
			g[i][j] = getchar() - '0';
		}
		getchar();
	}
	int q, r1, r2, c1, c2;
	scanf("%d\n", &q);
	loop(q) {
		scanf("%d %d %d %d\n", &r1, &c1, &r2, &c2);
		bfs(r1 - 1, c1 - 1);
		printf("%d\n", dist[r2 - 1][c2 - 1]);
	}
	return 0;
}

