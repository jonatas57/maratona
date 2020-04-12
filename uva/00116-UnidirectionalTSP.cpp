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

typedef tuple<int, int, int> tup;

vi dijkstra(vector<vi>& g, int n, int m) {
	vector<vi> next(n, vi(m, INF));
	vector<vi> dist(n, vi(m, INF));
	vector<vb> visit(n, vb(m, false));
	priority_queue<tup, vector<tup>, greater<tup>> q;
	loop(n) {
		dist[i][m - 1] = g[i][m - 1];
		q.emplace(1 - m, dist[i][m - 1], i);
	}
	while (!q.empty()) {
		int d, r, c;
		tie(c, d, r) = q.top();
		c = -c;
		q.pop();
		if (visit[r][c] or !c) continue;
		visit[r][c] = true;
		for (int i = -1;i <= 1;i++) {
			int nr = (r + i + n) % n;
			int nc = c - 1;
			int nd = d + g[nr][nc];
			if (nd < dist[nr][nc] or (nd == dist[nr][nc] and r < next[nr][nc])) {
				dist[nr][nc] = nd;
				next[nr][nc] = r;
				q.emplace(-nc, nd, nr);
			}
		}
	}
	int d = INF, id = 0;
	vi ans;
	loop(n) {
		if (dist[i][0] < d) {
			d = dist[i][0];
			id = i;
		}
	}
	for (int i = 0;id != INF;i++) {
		ans.push_back(id + 1);
		id = next[id][i];
	}
	ans.push_back(d);
	return ans;
}	

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	while (cin >> n >> m) {
		vector<vi> g(n, vi(m));
		loop(n) vloop(j, m) {
			cin >> g[i][j];
		}
		vi ans = dijkstra(g, n, m);
		loop(m) cout << (i ? " " : "") << ans[i];
		cout << endl << ans[m] << endl;
	}
	return 0;
}

