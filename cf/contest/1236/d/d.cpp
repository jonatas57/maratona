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

int walk(set<int>& vec, int& pos, int& dir, int& minmax, bool inv) {
	auto it = inv ? lower_bound(iter(vec), pos) : upper_bound(iter(vec), pos);
	int next = vec.empty() ? minmax + (inv ? -1 : 1) : *it;
	vec.erase(it, vec.end());
	minmax = inv ? max(next + 1, minmax) : min(next - 1, minmax);
	int dist = abs(minmax - pos);
	pos = minmax;
	dir++;
	if (dir == 4) dir = 0;
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	ll tot = (ll)n * (ll)m - k;
	vector<set<int>> hor(n), ver(m);
	int x, y;
	loop(k) {
		cin >> x >> y;
		x--, y--;
		hor[x].insert(y);
		ver[y].insert(x);
	}
	x = y = 0;
	vi minmax = {n - 1, m - 1, 0, 0}; //maxx, maxy, minx, miny;
	tot--;
	int dir = 0;
	map<ii, bool> vis;
	while (tot and (minmax[2] != minmax[0] or minmax[1] != minmax[3])) {
		int qtd = walk(dir & 1 ? ver[y] : hor[x], dir & 1 ? x : y, dir, minmax[dir], dir & 2);
		tot -= qtd;
		ii pos = make_pair(x, y);
		if (vis[pos]) break;
		vis[pos] = true;
	}
	cout << (tot ? "No" : "Yes") << endl;
	return 0;
}
