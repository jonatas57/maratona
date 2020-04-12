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

bool check(ll x) {
	return x >= 0 and x % 3 == 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		ll n, k, d1, d2;
		cin >> n >> k >> d1 >> d2;
		ll rem = n - k;
		bool x = check(rem - 2 * d1 - d2) and check(k - 2 * d2 - d1);
		bool w = check(rem - 2 * d2 - d1) and check(k - 2 * d1 - d2);
		if (d2 > d1) swap(d1, d2);
		bool y = check(rem - 2 * d1 + d2) and check(k - d1 - d2);
		swap(d1, d2);
		bool z = check(rem - 2 * d2 + d1) and check(k - d1 - d2);
		cout << (x or w or y or z ? "yes" : "no") << endl;
	}
	return 0;
}
