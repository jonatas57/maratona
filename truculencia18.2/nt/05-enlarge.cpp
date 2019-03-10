#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2


#define MAX                300000
#define H                  MAX / 2
vi primes;
vb pr;
int n, ans = 0;
void getprimes() {
	pr.resize(MAX + 1, true);
	pr[0] = pr[1] = false;
	for (int i = 2;i <= H;i++) {
		if (pr[i]) {
			primes.push_back(i);
			for (int j = i + i;j <= MAX;j += i) {
				pr[j] = false;
			}
		}
	}
	for (int i = H + 1;i <= MAX;i++) {
		if(pr[i]) primes.push_back(i);
	}
}
map<int, mii> facs;
void factor(int m) {
	for (int i = 0;primes[i] * primes[i] <= m;i++) {
		int x = primes[i];
		if (m % x == 0) {
			for (int i = 1;m % x == 0;i++) {
				m /= x;
				facs[x][i]++;
			}
		}
	}
	if (m > 1) {
		facs[m][1]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	getprimes();

	cin >> n;
	vi a(n);
	loop(n) cin >> a[i], factor(a[i]);

	each(p, facs) {
		each(x, p.second) {
			if (x.second != n) ans = max(ans, x.second);
		}
	}
	ans = ans ? n - ans : -1;
	cout << ans << endl;
	return 0;
}
