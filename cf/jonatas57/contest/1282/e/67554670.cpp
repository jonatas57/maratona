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
#define endl               "\n"

struct graph {
	int size;
	vector<list<int>> adj;
	vb visit;

	graph(int n) : size(n) {
		adj.resize(n + 1);
		visit.resize(n + 1, false);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vi getPath(int u = 1) {
		visit[u] = true;
		vi ans(1, u);
		each(v, adj[u]) {
			if (visit[v]) continue;
			vi x = getPath(v);
			ans.insert(ans.end(), iter(x));
		}
		return ans;
	}
};

void sort(int& a, int& b, int& c) {
	if (a > b) swap(a, b);
	if (a > c) swap(a, c);
	if (b > c) swap(b, c);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		graph g(n);
		int a, b, c;
		map<ii, int> cnt;
		map<tuple<int, int, int>, int> cuts;
		loop(n - 2) {
			cin >> a >> b >> c;
			sort(a, b, c);
			cuts[make_tuple(a, b, c)] = i + 1;
			vector<ii> edges = {{a, b}, {a, c}, {b, c}};
			each(p, edges) {
				cnt[p]++;
			}
		}
		for (auto& [p, q] : cnt) {
			if (q == 1) g.addEdge(p.first, p.second);
		}
		vi path = g.getPath();
		each(x, path) cout << x << " ";
		cout << endl;
		vi st(n), ans;
		for (size_t i = 0, j = 0;i < path.size();i++) {
			st[j++] = path[i];
			if (j >= 3) {
				while (true) {
					int a = st[j - 1], b = st[j - 2], c = st[j - 3];
					sort(a, b, c);
					try {
						ans.push_back(cuts.at(make_tuple(a, b, c)));
						st[j - 2] = st[j - 1];
						j--;
						if (j < 3) break;
					}
					catch (exception& e) {
						break;
					}
				}
			}
		}
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}
