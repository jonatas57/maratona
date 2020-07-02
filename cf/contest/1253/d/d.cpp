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
vector<ii> mm;
void init(int x) {
	id.resize(x);
	sz.resize(x, 1);
	mm.resize(x);
	loop(x) {
		id[i] = i;
		mm[i] = {i, i};
	}
}

int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
	mm[b] = {min(mm[a].first, mm[b].first), max(mm[a].second, mm[b].second)};
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	init(n);
	int u, v;
	loop(m) {
		cin >> u >> v;
		join(u - 1, v - 1);
	}
	int ans = 0;
	loop(n) {
		int x = find(i);
		for (int j = mm[x].first + 1;j < mm[x].second;j++) {
			ans += join(x, j);
			x = find(x);
		}
		i = mm[x].second;
	}
	cout << ans << endl;
	return 0;
}

