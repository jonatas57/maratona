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

vector<ll> a, acc;
ll n;

bool isprime(ll x) {
	if (x <= 1) return false;
	for (ll i = 2;i * i <= x;i++) {
		if (x % i == 0) return false;
	}
	return true;
};

ll calc(ll l, ll r) {
	ll del = r > l ? 1 : -1;
	ll end = r + del;
	for (ll i = l;i != end;i += del) {
		if (isprime(i)) {
			int lb = lower_bound(iter(a), i) - a.begin();
			int ub = upper_bound(iter(a), i) - a.begin();
			return acc.back() - acc[ub] - acc[lb] + i * (lb - n + ub);
		}
	}
	return INFLL;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	a.resize(n);
	acc.resize(n + 1, 0);
	loop(n) cin >> a[i];
	sort(iter(a));
	loop(n) acc[i + 1] = acc[i] + a[i];
	int med = n / 2;
	ll ans = min(calc(a[med], 2), calc(a[med], INF));
	if (n % 2 == 0) {
		ans = min(ans, calc(a[med - 1], a[med]));
	}
	cout << ans << endl;
	return 0;
}

