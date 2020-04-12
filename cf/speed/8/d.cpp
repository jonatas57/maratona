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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, x;
	cin >> n >> x;x--;
	vector<ll> a(n);
	ll minl = INF, minr = INF, l, r;
	loop(n) {
		cin >> a[i];
		if (i <= x) {
			if (minl >= a[i]) {
				minl = a[i];
				l = i;
			}
		}
		else if (i > x) {
			if (minr >= a[i]){
				minr = a[i];
				r = i;
			}
		}
	}
	ll y, p;
	if (minr < minl) y = minr, p = r; else y = minl, p = l;
	if (y) {
		ll cnt = n * y;
		loop(n) a[i] -= y;
		a[p] = cnt;
	}
	for (int i = x;;i--) {
		if (i < 0) i = n - 1;
		if (i == p) break;
		a[p]++;
		a[i]--;
	}
	loop(n) cout << a[i] << " ";cout << endl;
	return 0;
}
