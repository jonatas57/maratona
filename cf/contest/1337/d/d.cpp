#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3fffffffffffffffll
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

ll calc(ll x, ll y, ll z) {
	if (x == INFLL or y == INFLL or z == INFLL) return INFLL;
	return 2 * (x * (x - y - z) + y * (y - z) + z * z);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		vi n(3);
		vector<vector<ll>> ps(3);
		loop(3) cin >> n[i];
		ll x;
		loop(3) {
			vloop(j, n[i]) cin >> x, ps[i].push_back(x);
			ps[i].push_back(INFLL);
			sort(iter(ps[i]));
		}
		ll ans = calc(ps[0][0], ps[1][0], ps[2][0]);
		for (vi ids = {0, 0, 0};ans;) {
			bool p = false;
			loop(3) if (ps[i][ids[i]] != INFLL) p = true;
			if (!p) break;
			ll aux = INFLL;
			int id = -1;
			loop(3) {
				if (ps[i][ids[i]] == INFLL) continue;
				ll c = calc(ps[0][ids[0]] == INFLL ? ps[0][ids[0] - 1] : ps[0][ids[0] + (i == 0)], ps[1][ids[1]] == INFLL ? ps[1][ids[1] - 1] : ps[1][ids[1] + (i == 1)], ps[2][ids[2]] == INFLL ? ps[2][ids[2] - 1] : ps[2][ids[2] + (i == 2)]);
				if (c < aux) aux = c, id = i;
			}
			ans = min(ans, aux);
			if (id == -1) break;
			ids[id]++;
		}
		cout << ans << endl;
	}
	return 0;
}

