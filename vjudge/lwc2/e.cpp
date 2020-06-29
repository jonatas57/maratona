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

vi id, sz, ans, qtd;
vector<set<int>> gs;
void init(int x, vi& a) {
	sz.resize(x, 1);
	id.resize(x);
	gs.resize(x);
	loop(x) {
		id[i] = i;
		gs[i].insert(a[i]);
	}
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
void join(int a, int b, int i) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	each(x, gs[a]) {
		if (gs[b].insert(x).second) sz[b]++;
		else {
			qtd[x]--;
			if (qtd[x] == 1) ans[x] = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, q;
	cin >> n >> m >> q;
	int x;
	ans.resize(m, -1);
	qtd.resize(m, 0);
	vi aux;
	loop(n) {
		cin >> x;
		x--;
		aux.push_back(x);
		qtd[x]++;
	}
	loop(m) if (qtd[i] == 1) ans[i] = 0;
	init(n, aux);
	int a, b;
	loop(q) {
		cin >> a >> b;
		join(a - 1, b - 1, i + 1);
	}
	each(x, ans) cout << x << endl;
	return 0;
}

