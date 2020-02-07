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

	vector<vector<ll>> xp = {{1, 2}, {1, 3}, {1, 5}};
	each(v, xp) {
		while (v.back() < LLONG_MAX / v[1]) v.push_back(v.back() * v[1]);
		cerr << v.size() << endl;
	}
	vector<ll> a;
	each(x, xp[0]) each(y, xp[1]) each(z, xp[2]) {
		if (x <= LLONG_MAX / y / z and y <= LLONG_MAX / x / z and z <= LLONG_MAX / y / z) {
			a.push_back(x * y * z);
		}
	}
	sort(iter(a));
	cout << "The 1500'th ugly number is " << a[1499] << "." << endl;
	return 0;
}

