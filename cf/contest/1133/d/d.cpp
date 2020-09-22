#include <bits/stdc++.h>
#include <numeric>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct rat {
	int n, d;
	rat(int a, int b) {
		int x = gcd(a, b);
		n = a / x;
		d = b / x;
		if (d < 0) {
			d = -d;
			n = -n;
		}
	}
	bool operator<(const rat& x) const {
		if (n < x.n) return true;
		return (n == x.n && d <x.d);
	}
};
map<rat, int> cnt;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(n), b(n);
	loop(n) cin >> a[i];
	loop(n) cin >> b[i];
	int zero = 0;
	loop(n) {
		if (a[i] == 0 and b[i] == 0) zero++;
		if (a[i] != 0) {
			cnt[rat(b[i], a[i])]++;
		}
	}
	int m = 0;
	each(p, cnt) m = max(m, p.second);
	cout << zero + m << endl;
	return 0;
}

