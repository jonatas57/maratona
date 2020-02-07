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

struct frac {
	ll n, d;
	frac(ll n = 0, ll d = 1) : n(n), d(d) {
		simpl();
	}
	void operator+=(frac f) {
		int m = __gcd(d, f.d);
		n *= f.d / m;
		n += d / m * f.n;
		d *= f.d / m;
	}
	void operator*=(ll x) {
		n *= x;
		simpl();
	}
	void simpl() {
		ll m = __gcd(n, d);
		n /= m;
		d /= m;
	}
	void inv() {
		swap(n, d);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int s;
	cin >> s;
	for (int i = 1;i <= s;i++) {
		frac ans;
		int n, d;
		cin >> n;
		loop(n) {
			cin >> d;
			ans += frac(1, d);
		}
		ans.inv();
		ans *= n;
		cout << "Case " << i << ": " << ans.n << "/" << ans.d << endl;
	}
	return 0;
}

