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

vector<ll> divs(ll a) {
	set<ll> ds;
	for (ll i = 1;i * i <= a;i++) {
		if (a % i == 0) {
			ds.insert(i);
			ds.insert(a / i);
		}
	}
	return vector<ll>(iter(ds));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll a;
	string s;
	vector<ll> acc(1, 0);
	cin >> a >> s;
	each(c, s) {
		acc.push_back(acc.back() + c - '0');
	}
	int n = s.length();
	vector<ll> cnt(9 * n + 1, 0);
	int cntl = 9 * n + 1;
	for (int i = 1;i <= n;i++) {
		for (int j = 0;j < i;j++) {
			cnt[acc[i] - acc[j]]++;
		}
	}
	vector<ll> ds = divs(a);
	if (ds.empty()) ds.push_back(0);
	int l = ds.size();
	ll ans = 0;
	loop(l) {
		ans += (ds[i] < cntl ? cnt[ds[i]] : 0) * (ds[l - i - 1] < cntl ? cnt[ds[l - i - 1]] : 0);
	}
	cout << ans << endl;
	return 0;
}
