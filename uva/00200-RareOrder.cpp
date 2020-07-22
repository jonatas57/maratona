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
	map<char, map<char, bool>> adj;
	map<char, int> deg;
	void addEdge(char a, char b) {
		deg[a], deg[b];
		if (!adj[a][b]) deg[b]++;
		adj[a][b] = true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	vector<string> ss;
	while (cin >> s and s != "#") ss.push_back(s);
	graph g;
	int n = ss.size();
	loop(n - 1) {
		for (int j = 0;ss[i][j] and ss[i + 1][j];j++) {
			if (ss[i][j] != ss[i + 1][j]) {
				g.addEdge(ss[i][j], ss[i + 1][j]);
				break;
			}
		}
	}
	string ans = "";
	queue<char> q;
	each(p, g.deg) {
		if (!p.second) q.push(p.first);
	}
	while (!q.empty()) {
		char u = q.front();
		q.pop();
		ans += u;
		each(p, g.adj[u]) {
			g.deg[p.first]--;
			if (!g.deg[p.first]) q.push(p.first);
		}
	}
	cout << ans << endl;
	return 0;
}

