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

ll f(ll k, ll x) {
	return k * k / x + k;
}

vector<ii> fats(int x) {
	mii cnt;
	for (int i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			cnt[i]++;
			x /= i;
		}
	}
	if (x > 1) cnt[x]++;
	return vector<ii>(iter(cnt));
}

vector<ll> divs(int x) {
	vector<ii> fs = fats(x);
	each(p, fs) p.second *= 2;
	set<ll> ans;
	ans.insert(1);
	for (auto& [p, e] : fs) {
		vector<ll> aux;
		ll r = 1;
		loop(e) {
			r *= p;
			each(y, ans) {
				aux.push_back(y * r);
			}
		}
		ans.insert(iter(aux));
	}
	return vector<ll>(iter(ans));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k;
	cin >> k;
	vector<ii> ans;
	vector<ll> ds = divs(k);
	int x = ds.size();
	cout << x << endl;
	loop(x) {
		cout << ds[i] + k << " " << f(k, ds[i]) << endl;
	}
	return 0;
}

