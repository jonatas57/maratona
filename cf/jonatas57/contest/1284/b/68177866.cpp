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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<ii> mins, maxs;
	vb asc(n);
	loop(n) {
		int m, x;
		cin >> m;
		mins.emplace_back(INF, -1);
		maxs.emplace_back(0, -1);
		vloop(j, m) {
			cin >> x;
			if (x > mins[i].first) asc[i] = true;
			if (x < mins[i].first) mins[i] = {x, i};
			if (x > maxs[i].first) maxs[i] = {x, i};
		}
	}
	ll ans = 0;
	vector<ii> aux;
	int na = 0, ascs = 0;
	loop(n) {
		if (!asc[i]) na++, aux.emplace_back(maxs[i]);
		else ascs++;
	}
	sort(iter(mins));
	sort(iter(aux));
	for (auto& [x, i] : mins) {
		if (asc[i]) ans += n;
		else {
			auto it = lower_bound(iter(aux), ii(x, INF));
			ans += ascs + na - (it - aux.begin());
		}
	}
	cout << ans << endl;
	return 0;
}

