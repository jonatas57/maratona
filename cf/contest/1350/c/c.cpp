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
	vi a(n);
	vector<ll> pregcd(n + 1, 0), sufgcd(n + 1, 0);
	loop(n) {
		cin >> a[i];
		pregcd[i + 1] = gcd(a[i], pregcd[i]);
	}
	for (int i = n - 1;i >= 0;i--) {
		sufgcd[i] = gcd(a[i], sufgcd[i + 1]);
	}
	ll ans = 1;
	for (int i = 1;i <= n;i++) {
		ans = lcm(ans, gcd(pregcd[i - 1], sufgcd[i]));
	}
	cout << ans << endl;
	return 0;
}

