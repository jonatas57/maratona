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

ll getsum(ll x) {
	return (x * (x + 1)) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	ll x;
	cin >> n >> x;
	vector<ll> d(n + n);
	loop(n) cin >> d[i], d[i + n] = d[i];
	ll ans = 0;
	ll last = 0, qtd = 0, sum = 0;
	for (int i = n + n - 1, j = i;i >= n;i--) {
		while (qtd + d[j] - last <= x) {
			qtd += d[j] - last;
			sum += getsum(d[j] - last);
			j--;
			last = 0;
		}
		if (last) {
			sum += getsum(d[j] - last);
			last += x - qtd;
			sum -= getsum(d[j] - last);
		}
		else {
			last = x - qtd;
			sum += getsum(d[j]) - getsum(d[j] - last);
		}
		qtd = x;
		ans = max(ans, sum);
		if (i > j) {
			sum -= getsum(d[i]);
			qtd -= d[i];
		}
		else {
			last = 0;
			qtd = 0;
			sum = 0;
			j--;
		}
	}
	cout << ans << endl;
	return 0;
}

