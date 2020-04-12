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

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

auto nearest(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> p) {
	return dist(p, a) < dist(p, b) ? a : b;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll x, y, ax, ay, bx, by;
	cin >> x >> y >> ax >> ay >> bx >> by;
	vector<pair<ll, ll>> ls, rs;
	ll maxx = (LLONG_MAX - bx) / ax, maxy = (LLONG_MAX - by) / ay;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	for (ll i = x, j = y;i < maxx and j < maxy;i = ax * i + bx, j = ay * j + by) {
		if (x <= xs) ls.emplace_back(i, j);
		else rs.emplace_back(i, j);
	}
	pair<ll, ll> pos(xs, ys);
	auto comp = [pos](pair<ll, ll> a, pair<ll, ll> b) {
		return dist(pos, a) < dist(pos, b);
	};
	sort(iter(ls), comp);
	sort(iter(rs), comp);
	int ans = 0, l = ls.size(), r = rs.size();/*@*/
	for (auto [a, b] : ls) cerr << a << " " << b << endl;
	cerr << endl;
	for (auto [a, b] : rs) cerr << a << " " << b << endl;/*@*/
	for (int i = 0, j = 0;i < l or j < r;) {
		auto next = (i == l ? rs[j] : (j == r ? ls[i] : nearest(ls[i], rs[j], pos)));
		if (i < l and next == ls[i]) i++; else j++;
		ll d = dist(pos, next);
		if (t >= d) {
			t -= d;
			pos = next;
			ans++;
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}

