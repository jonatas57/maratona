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

set<int> divs(int n) {
	set<int> ds;
	ds.insert(1);
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			set<int> x;
			int aux = i;
			while (n % i == 0) {
				each(y, ds) x.insert(y * aux);
				aux *= i;
				n /= i;
			}
			ds.insert(iter(x));
		}
	}
	if (n > 1) {
		set<int> x;
		each(y, ds) x.insert(n * y);
		ds.insert(iter(x));
	}
	return ds;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		int a = -1, b = -1, l = INF;
		each(i, divs(n)) {
			if (i == n) continue;
			if (l > lcm(i, n - i)) {
				a = i;
				b = n - i;
				l = lcm(i, n - i);
			}
		}
		cout << a << " " << b << endl;
	}
	return 0;
}

