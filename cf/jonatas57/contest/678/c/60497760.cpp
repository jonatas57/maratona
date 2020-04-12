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

ll mmc(ll a, ll b) {
	return a * b / __gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, a, b, p, q;
	cin >> n >> a >> b >> p >> q;
	ll maxa = n / a, maxb = n / b, eit = n / mmc(a, b);
	if (p >= q) maxb -= eit; else maxa -= eit;
	ll ans = maxa * p + maxb * q;
	cout << ans << endl;
	return 0;
}

