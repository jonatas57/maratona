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

struct graph {
	int size;
	vector<list<int>> adj; 
	graph(int n) : size(n) {
		adj.resize(n);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

int tot;

vi setColor(graph& g) {
	tot = 0;
	vb visit(g.size, false);
	vi c(g.size, 0);
	visit[0] = true;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		each(v, g.adj[x]) {
			if (!visit[v]) {
				visit[v] = true;
				c[x]++;
				c[v]++;
				tot += 2;
				q.push(v);
			}
		}
	}
	return c;
}

set<int> findClique(graph& g, int v) {
	set<int> cl;
	int clsize = 1;
	cl.insert(v);
	loop(g.size) {
		if (cl.count(i)) continue;
		int cnt = 0;
		each(u, g.adj[i]) {
			if (cl.count(u)) {
				cnt++;
				if (cnt == clsize) {
					cl.insert(v);
					clsize++;
					break;
				}
			}
		}
	}
	return cl;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph g(n);
	int a, b;
	loop(m) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	vi c = setColor(g);
	vector<set<int>> cls;
	vb inClique(n, false);
	loop(n) if (!c[i]) c[i]++, tot++;
	int y = 1;
	vector<vector<int>> ans(n);
	for (int i = 0;tot > 5000;i++) {
		if (!inClique[i]) {
			set<int> cl = findClique(g, i);
			int l = cl.size();
			tot -= l * (l - 2);
			each(x, cl) {
				inClique[x] = true;
				c[x] -= l - 2;
				ans[x].push_back(y);
			}
			y++;
		}
	}
			
	loop(n) {
		cout << ans[i].size() << endl;
		each(x, ans[i]) {
			cout << i + 1 << " " << x << endl;
		}
	}
}

