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
	vector<ll> a(n);
	ll m = 1000, stonks = 0;
	int tobuy = 0, tosell = -1;
	loop(n) {
		cin >> a[i];
		if (i) {
			if (a[i] < a[i - 1]) {
				if (stonks) {
					m += stonks * a[tosell];
					stonks = 0;
				}
				tobuy = i;
			}
			else if (a[i] > a[i - 1]) {
				ll x = m / a[tobuy];
				m -= x * a[tobuy];
				stonks += x;
				tosell = i;
			}
		}
	}
	if (stonks) m += stonks * a[tosell];
	cout << m << endl;
	return 0;
}

