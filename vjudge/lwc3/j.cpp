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

struct frac {
	ll n, d;
	bool up;
	frac(ll a = 0, ll b = 1, bool c = true) : n(a), d(b), up(c) {
		if (d < 0) d = -d, n = -n;
		simpl();
	}
	void simpl() {
		ll m = __gcd(abs(n), d);
		if (m) {
			n /= m;
			d /= m;
		}
	}
	bool operator<(const frac& f) const {
		return up == f.up ? n * f.d < d * f.n : up < f.up;
	}
};

int lis(vector<ii>& hs) {
	int n = hs.size();
	sort(iter(hs));
	vi a(n);
	loop(n) a[i] = hs[i].second;
	vi d(n + 1, INF);
	d[0] = -INF;
	loop(n) {
		int j = upper_bound(iter(d), a[i]) - d.begin();
		if (d[j - 1] < a[i] and a[i] < d[j]) d[j] = a[i];
	}
	int ans = 0;
	loop(n + 1) {
		if (d[i] < INF) ans = i;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ii tv;
	int n;
	cin >> tv.first >> tv.second >> n;
	int x, y, h;
	map<frac, vector<ii>> ls;
	loop(n) {
		cin >> x >> y >> h;
		x -= tv.first, y -= tv.second;
		ls[frac(x, y, y > 0)].emplace_back(__gcd(abs(x), abs(y)), h);
	}
	int ans = 0;
	for (auto& [f, v] : ls) {
		ans += lis(v);
	}
	cout << ans << endl;
	return 0;
}

