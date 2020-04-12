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

struct frac {
	ll n, d;
	frac(ll a, ll b) : n(a), d(b) {}
	frac operator*(frac f) {
		return frac(n * f.n, d * f.d);
	}
	bool operator>(ll x) {
		return n > d * x;
	}
};

bool check(frac f) {
	return f > 1;
}
bool check2(frac f) {
	return f > INF;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	frac x(b, a), y(d, c), z(f, e);
	if (check(x * y * z) or check2(y) or (check2(x) and d)) {
		cout << "Ron" << endl;
	}
	else cout << "Hermione" << endl;
	return 0;
}

