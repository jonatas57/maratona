#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()

struct graph {
	int size;
	map<ll, list<ll>> adj;
	set<ll> nodes;
	graph() : size(0) {}
	void addEdge(ll a, ll b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	void addNode(ll n) {
		nodes.insert(n);
		size++;
	}
};

int bfs(graph& g, ll u, ll v) {
	map<ll, bool> visit;
	map<ll, int> dist;
	each(x, g.nodes) dist[x] = INF, visit[x] = false;
	queue<ll> q;
	visit[u] = true;
	dist[u] = 0;
	q.push(u);
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		each(y, g.adj[x]) {
			if (!visit[y] and (u != x || v != y)) {
				visit[y] = true;
				dist[y] = dist[x] + 1;
				q.push(y);
			}
		}
	}
	return dist[v];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vi bits(64, 0);
	int n;
	cin >> n;
	ll x;
	int ans = INF;
	graph g;
	loop(n) {
		cin >> x;
		g.addNode(x);
		for (int i = 0;x;i++, x >>= 1) {
			if (x & 1) {
				if (++bits[i] == 3) {
					ans = 3;
				}
			}
		}
	}
	if (ans > 3) {
		each(u, g.nodes) {
			each(v, g.nodes) {
				if (u < v and u & v) {
					g.addEdge(u, v);
				}
			}
		}
		each(u, g.nodes) {
			each(v, g.adj[u]) {
				if (u < v) ans = min(ans, bfs(g, u, v) + 1);
			}
		}
	}
	cout << (ans >= INF ? -1 : ans) << endl;
	return 0;
}
