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
const double EPS = 1e-8;
const double EPS2 = 1e-5;
int p, q, r, s, t, u;

double f(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double der(double x) {
	double c = cos(x);
	return -p * exp(-x) + q * c - r * sin(x) + s / (c * c) + 2 * t * x;
}

int sig(double x) {
	return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	while (cin >> p >> q >> r >> s >> t >> u) {
		double l = 0, h = 1;
		while (abs(h - l) > EPS) {
			double mid = avg(l, h);
			if (sig(f(mid)) == sig(der(mid))) h = mid;
			else l = mid;
		}
		if (abs(f(h)) < EPS2) cout << fixed << setprecision(4) << h << endl;
		else cout << "No solution" << endl;
	}
	return 0;
}

