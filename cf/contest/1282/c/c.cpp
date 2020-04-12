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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int m;
	cin >> m;
	loop(m) {
		int n, t, a, b;
		cin >> n >> t >> a >> b;
		vector<ii> psd(n);
		loop(n) cin >> psd[i].first;
		loop(n) cin >> psd[i].second;
		auto pst = psd;
		sort(iter(psd), [](ii a, ii b) { return a.first < b.first; });
		sort(iter(pst), [](ii a, ii b) { return a.second < b.second; });
		int ans = 0, mand = 0;
		vi times;
		for (auto& [d, t] : psd) {
			int x = times.size() ? times.back() : 0;
			x += d ? b : a;
			times.push_back(x);/*@*/cerr <<x << " ";/*@*/
		}/*@*/cerr << endl;/*@*/
		for (auto& [d, t] : pst) {
			auto it = upper_bound(iter(times), t - 1 - mand);
			ans = max(ans, *it);
			auto f = find(iter(psd), ii(d, t));
			mand += d ? b : a;
			psd.erase(f);
		}
		auto it = upper_bound(iter(times), t - mand);
		ans = max(ans, *it);
		cout << ans << endl;
	}
	return 0;
}

