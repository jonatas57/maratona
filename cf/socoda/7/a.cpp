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
vector<string> apto;
vector<vb> visit;

void bfs(int x, int y) {
	visit[x][y] = true;
	queue<ii> q;
	q.emplace(x, y);
	int minx = x, miny = y, maxx = x, maxy = y;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		vloop(dir, 4) {
			int nx = x + (dir == 0) - (dir == 1);
			int ny = y + (dir == 2) - (dir == 3);
			if (nx < 0 or nx >= n or ny < 0 or ny >= m or visit[nx][ny]) continue;
			if (apto[nx][ny] == '.' or (minx <= nx and nx <= maxx and miny <= ny and ny <= maxy)) {
				apto[nx][ny] = '.';
				minx = min(nx, minx), maxx = max(nx, maxx), miny = min(ny, miny), maxy = max(ny, maxy);
				visit[nx][ny] = true;
				q.emplace(nx, ny);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m;
	loop(n) {
		string s;
		cin >> s;
		apto.push_back(s);
	}
	visit.assign(n, vb(m, false));
	loop(n) {
		vloop(j, m) {
			if (visit[i][j] or apto[i][j] == '*') continue;
			bfs(i, j);
		}
	}
	each(s, apto) cout << s << endl;
	return 0;
}

