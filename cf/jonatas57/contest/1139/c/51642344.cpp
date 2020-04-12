#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100010
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

mii cnt;
int comp;
int id[MAX], sz[MAX];
void makeset(int x) {
	loop(x + 1) {
		id[i] = i;
		sz[i] = 1;
	}
}
int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
void join(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
	comp--;
}

ll fastxp(int b, int e) {
	if (e == 1) return (ll)b;
	ll c = fastxp(b, e / 2);
	c *= c;
	c %= MOD;
	if (e & 1) c *= (ll)b;
	c %= MOD;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	comp = n;
	makeset(n);
	int a, b, c;
	loop(n - 1) {
		cin >> a >> b >> c;
		if (!c) join(a, b);
	}
	rep(1, n + 1, 1) cnt[find(i)]++;
	ll ans = fastxp(n, k);
	each(p, cnt) {
		ans -= fastxp(p.second, k);
	}
	ans %= MOD;
	if (ans < 0) ans += MOD;
	cout << ans << endl;
	return 0;
}

