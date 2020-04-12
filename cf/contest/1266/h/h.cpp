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
	vector<vi> adj;
	graph(int n) : size(n), adj(n, vi(2, -1)) {}
	void addEdge(int a, int b, int c) {
		adj[a][c] = b;
	}
};

vector<unordered_map<ll, int>> used;

void run(graph& g) {
	used.resize(g.size);
	int v = 0, x = g.size - 1;
	ll state = 0, t = 1;
	while (v != x) {
		if (!used[v][state]) used[v][state] = t++;
		ll mask = 1 << v;
		state ^= mask;
		v = g.adj[v][(state & mask) > 0];
	}
	used[v][state] = t++;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	graph g(n);
	loop(n - 1) {
		int x;
		vloop(j, 2) cin >> x, g.addEdge(i, x - 1, j);
	}
	run(g);
	int q;
	cin >> q;
	int v;
	string s;
	loop(q) {
		cin >> v >> s;
		ll state = 0, b = 1;
		each(c, s) state += (c == 'R') * b, b *= 2;
		try {
			cout << used[v - 1].at(state) - 1 << endl;
		}
		catch (exception& e) {
			cout << -1 << endl;
		}
	}
	return 0;
}

