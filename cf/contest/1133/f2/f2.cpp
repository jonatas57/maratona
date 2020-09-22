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

vi id, sz;
void init(int x) {
	id.resize(x);
	sz.resize(x, 1);
	loop(x) id[i] = i;
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
	return true;
}

struct graph {
	int size;
	vector<ii> adj;
	graph(int n) : size(n) {}
	void addEdge(int a, int b) {
		if (a > b) swap(a, b);
		adj.emplace_back(a, b);
	}
};

vector<ii> kruskall2(graph& g, int d) {
	vector<ii> ans;
	init(g.size);
	int cnt = 0, cs = g.size;
	for (auto& [u, v] : g.adj) {
		if (u == 0) continue;
		if (join(u, v)) {
			ans.emplace_back(u, v);
			cs--;
			if (u == 0) cnt++;
		}
	}
	if (cs == d + 1) {
		for (auto& [u, v] : g.adj) {
			if (u) break;
			if (join(u, v)) {
				ans.emplace_back(u, v);
				cnt++;
				if (cnt == d) break;
			}
		}
	}
	else ans.clear();
	if (cnt < d) ans.clear();
	return ans;
}
vector<ii> kruskall(graph& g, int d) {
	vector<ii> ans;
	init(g.size);
	int cnt = 0, cs = g.size;
	for (auto& [u, v] : g.adj) {
		if (!u) continue;
		if (join(u, v)) {
			cs--;
		}
	}
	if (cs <= d + 1) {
		cs = g.size;
		for (auto& [u, v] : g.adj) {
			if (u or cnt == d) break;
			if (join(u, v)) {
				ans.emplace_back(u, v);
				cnt++;
			}
		}
		init(g.size);
		for (auto& [u, v] : ans) join(u, v);
		for (auto& [u, v] : g.adj) {
			if (u == 0 and cnt == d) continue;
			if (join(u, v)) {
				ans.emplace_back(u, v);
				if (!u) cnt++;
			}
		}
	}
	if (cnt < d) ans.clear();
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, d;
	cin >> n >> m >> d;
	graph g(n);
	loop(m) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u - 1, v - 1);
	}
	sort(iter(g.adj));
	vector<ii> ans = kruskall(g, d);
	if (ans.empty()) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (auto& [u, v] : ans) {
			cout << u + 1 << " " << v + 1 << endl;
		}
	}
	return 0;
}

