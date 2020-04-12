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

	int n, k;
	cin >> n >> k;
	vector<ii> ds;
	int x;
	loop(n) {
		cin >> x;
		ds.emplace_back(x, i);
	}
	sort(iter(ds));
	vector<vi> dists(n);
	vector<ii> es;
	vi deg(n, 0);
	int u = -1;
	bool p = true;
	for (auto& [d, v] : ds) {
		if (d) {
			if (dists[d - 1].empty()) {
				p = false;
				break;
			}
			else {
				int x = dists[d - 1].back();
				es.emplace_back(x, v);
				deg[x]++;
				deg[v]++;
				if (deg[x] >= k) dists[d - 1].pop_back();
				if (deg[v] < k) dists[d].push_back(v);
			}
		}
		else if (u == -1) {
			u = v;
			dists[0].push_back(u);
		}
		else {
			p = false;
			break;
		}
	}
	if (p) {
		cout << es.size() << endl;
		for (auto& [a, b] : es) {
			cout << a + 1 << " " << b + 1 << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

