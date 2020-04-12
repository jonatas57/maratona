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
void init(int n) {
	id.resize(n);
	sz.resize(n, 1);
	loop(n) id[i] = i;
}

int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }

bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	init(n);
	vector<ll> a(n);
	priority_queue<tuple<ll, ll, ll>> os;
	int r = 0;
	loop(n) {
		cin >> a[i];
		if (a[i] < a[r]) r = i;
	}
	loop(n) {
		os.emplace(-a[i] - a[r], i, r);
	}
	ll x, y, w;
	ll ans = 0;
	loop(m) cin >> x >> y >> w, os.emplace(-w, x - 1, y - 1);
	while (!os.empty()) {
		ll u, v, z;
		tie(z, u, v) = os.top();
		os.pop();
		if (join(u, v)) {
			ans -= z;
		}
	}
	cout << ans << endl;
	return 0;
}

