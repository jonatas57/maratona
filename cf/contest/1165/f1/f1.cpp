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

	int n, m;
	cin >> n >> m;
	vi k(n);
	int tot = 0;
	loop(n) cin >> k[i], tot += k[i];
	vector<tuple<int, int, int>> ofs;
	int d, t;
	loop(m) {
		cin >> d >> t;
		t--;
		ofs.emplace_back(d, INF, t);
	}
	sort(iter(ofs), [](tuple<int, int, int>& a, tuple<int, int, int>& b) {
		return make_tuple(get<2>(a), get<0>(a), get<1>(a)) < make_tuple(get<2>(b), get<0>(b), get<1>(b));
	});
	loop(m - 1) {
		if (get<2>(ofs[i]) == get<2>(ofs[i + 1])) {
			get<1>(ofs[i]) = get<0>(ofs[i + 1]);
		}
	}
	sort(iter(ofs));
	int l = tot - 1, r = tot << 1;
	while (l < r) {
		int mid = avg(l, r);
		int maxb = 0, lastd = 0, totb = 0;
		vi bought(n, 0);
		for (auto& [d, no, t] : ofs) {
			if (d > mid) break;
			if (no <= mid) continue;
			maxb += d - lastd;
			if (bought[t] < k[t]) {
				int x = min(maxb, k[t] - bought[t]);
				maxb -= x;
				totb += x;
				bought[t] += x;
			}
			lastd = d;
		}
		maxb += mid - lastd;
		if ((tot - totb) * 2 <= maxb) {
			totb = tot;
		}
		if (totb == tot) r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}

