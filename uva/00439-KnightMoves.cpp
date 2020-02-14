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

vector<ii> dirs = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};

ii conv(string a) { return {a[0] - 'a', a[1] - '1'}; }

int bfs(string a, string b) {
	if (a == b) return 0;
	vector<vb> visit(8, vb(8, false));
	vector<vi> dist(8, vi(8, INF));
	queue<ii> q;
	int x, y, p, r;
	tie(x, y) = conv(a);
	tie(p, r) = conv(b);
	visit[x][y] = true;
	dist[x][y] = 0;
	q.emplace(x, y);
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		int i, j;
		each(d, dirs) {
			tie(i, j) = d;i += x;j += y;
			if (i < 0 or i >= 8 or j < 0 or j >= 8 or visit[i][j]) continue;
			visit[i][j] = true;
			dist[i][j] = dist[x][y] + 1;
			q.emplace(i, j);
			if (i == p and j == r) return dist[i][j];
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string a, b;
	while (cin >> a >> b) {
		cout << "To get from " << a << " to " << b << " takes " << bfs(a, b) << " knight moves." << endl;
	}
	return 0;
}

