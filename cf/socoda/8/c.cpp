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

int len(ii& a) {
	return a.second - a.first + 1;
}

int divs(ii& a, int p) {
	int x, y;
	tie(x, y) = a;
	if (x % p) x += p - x % p;
	if (y % p) y -= y % p;
	return (y - x) / p + 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, p;
	cin >> n >> p;
	vector<ii> a(n);
	loop(n) {
		cin >> a[i].first >> a[i].second;
	}
	vector<double> ps(n);
	loop(n) {
		ps[i] = (double)divs(a[i], p) / len(a[i]);
	}
	ps.push_back(ps[0]);
	double ans = 0;
	loop(n) {
		ans += 2000.0 * (ps[i] + ps[i + 1] - ps[i] * ps[i + 1]);
	}
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}

