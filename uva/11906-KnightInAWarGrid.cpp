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

int r, c, m, n, w;
vector<vb> vis, p;
vi dx = {1, 1, 1, 1, -1, -1, -1, -1}, dy = {1, 1, -1, -1, -1, -1, 1, 1};

ii dfs(int x, int y) {
	vis[x][y] = true;
	set<ii> pos;
	loop(8) {
		int nx = x + dx[i] * (i & 1 ? n : m);
		int ny = y + dy[i] * (i & 1 ? m : n);
		if (nx >= 0 and nx < r and ny >= 0 and ny < c and p[nx][ny]) {
			pos.emplace(nx, ny);
		}
	}
	int nx, ny, ev = 0, od = 0;
	each(p, pos) {
		tie(nx, ny) = p;
		if (!vis[nx][ny]) {
			int e, o;
			tie(e, o) = dfs(nx, ny);
			ev += e;
			od += o;
		}
	}
	if (pos.size() & 1) od++; else ev++;
	return {ev, od};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> r >> c >> m >> n >> w;
		vis.assign(r, vb(c, false));
		p.assign(r, vb(c, true));
		int x, y;
		loop(w) {
			cin >> x >> y;
			p[x][y] = false;
		}
		tie(x, y) = dfs(0, 0);
		cout << "Case " << i + 1 << ": " << x << " " << y << endl;
	}
	return 0;
}

