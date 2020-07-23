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

struct graph {
	int size;
	vector<list<int>> adj;
	map<string, int> conv;
	vector<string> names;
	int last;
	graph(int n) : size(n), adj(n), names(n), last(0) {}
	int addNode(string& s) {
		if (!conv.count(s)) {
			names[last] = s;
			conv[s] = last++;
		}
		return conv[s];
	}
	void addEdge(string& a, string& b) {
		int x = addNode(a);
		int y = addNode(b);
		adj[x].push_back(y);
	}
};

vi id, low, st;
vb used;
vector<vi> sccs;
int tempo = 0;

void dfs(graph& g, int u) {
	id[u] = low[u] = tempo++;
	st.push_back(u);
	used[u] = true;
	each(v, g.adj[u]) {
		if (id[v] == -1) {
			dfs(g, v);
			low[u] = min(low[u], low[v]);
		}
		else if (used[v]) {
			low[u] = min(low[u], id[v]);
		}
	}
	if (low[u] == id[u]) {
		vi sc;
		int v;
		do {
			v = st.back();
			used[v] = false;
			sc.push_back(v);
			st.pop_back();
		} while (v != u);
		sccs.push_back(sc);
	}
}

void tarjan(graph& g) {
	int n = g.size;
	id.assign(n, -1);
	low.assign(n, INF);
	used.assign(n, false);
	sccs.clear();
	loop(n) {
		if (id[i] == -1) {
			dfs(g, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	for (int i = 1;cin >> n >> m and n | m;i++) {
		if (i > 1) cout << endl;
		graph g(n);
		string a, b;
		loop(m) {
			cin >> a >> b;
			g.addEdge(a, b);
		}
		tarjan(g);
		cout << "Calling circles for data set " << i << ":" << endl;
		each(v, sccs) {
			loop((int)v.size()) {
				if (i) cout << ", ";
				cout << g.names[v[i]];
			}
			cout << endl;
		}
	}
	return 0;
}

