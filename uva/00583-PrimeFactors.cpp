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

vector<ll> fat(ll n) {
	vector<ll> fs;
	if (n < 0) {
		fs.push_back(-1);
		n = abs(n);
	}
	for (ll i = 2;i * i <= n;i++) {
		while (n % i == 0) {
			fs.push_back(i);
			n /= i;
		}
	}
	if (n > 1) fs.push_back(n);
	return fs;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	while (cin >> n and n) {
		auto fs = fat(n);
		int l = fs.size();
		cout << n << " =";
		loop(l) {
			if (i) cout << " x";
			cout << " " << fs[i];
		}
		cout << endl;
	}
	return 0;
}

