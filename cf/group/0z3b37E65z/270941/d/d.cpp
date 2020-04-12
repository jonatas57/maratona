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

typedef tuple<int, int, int> tup;

bool comp(tup a, tup b) {
	return get<0>(a) > get<0>(b) and get<1>(a) > get<1>(b);
}

vi dp;

vi lis(vector<tup>& a, int n) {
	dp.resize(n, 1);
	vi par(n, -1);
	int ans = 1;
	for (int i = 1;i < n;i++) {
		for (int j = 0;j < i;j++) {
			if (comp(a[i], a[j])) {
				if (dp[j] + 1 > dp[i]) {
					par[i] = j;
					dp[i] = dp[j] + 1;
				}
				ans = max(ans, dp[i]);
			}
		}
	}
	vi rec;
	for (int i = n - 1;i >= 0 and ans;) {
		if (dp[i] == ans) {
			rec.push_back(get<2>(a[i]));
			ans--;
			i = par[i];
		}
		else i--;
	}
	return vi(riter(rec));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, w, h;
	cin >> n >> w >> h;
	vector<tup> a;
	int x, y;
	loop(n) {
		cin >> x >> y;
		if (x > w and y > h) a.emplace_back(x, y, i + 1);
	}
	sort(iter(a));
	vi ans = lis(a, a.size());
	cout << ans.size() << endl;
	each(x, ans) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

