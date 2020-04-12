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

typedef tuple<int, int, ll> point;

bool comp(point& a, point& b) {
	return max(get<0>(a), get<1>(a)) < max(get<0>(b), get<1>(b));
}

bool comp2(point& a, int b) {
	return max(get<0>(a), get<1>(a)) < b;
}

ll solve(vector<point>& ps, int l, int r) {
	if (l == r) return 0;
	int mid = avg(l, r);
	auto midit = upper_bound(iter(ps), mid, comp2);
	ll left = solve(ps, 0, mid);
	ll right = solve(ps, mid + 1, r);
	ll cost = 0;
	auto st = midit, en = midit;
	int x, y;
	int m = max(x, y);
	ll c;
	for (auto it = ps.begin();it != midit;it--) {
		if ()
	}
	for (auto it = midit;it != ps.end();it++) {

	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<point> ps;
	int x, y, c;
	loop(n) {
		cin >> x >> y >> c;
		ps.emplace_back(x, y, c);
	}
	sort(iter(ps), comp);
	cout << solve(ps, 0, n - 1) << endl;
	return 0;
}
