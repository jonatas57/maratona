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
	ll a, b;
	frac(ll a = 0, ll b = 1) : a(a), b(b) { simpl(); }
	bool operator<(ll x) {
		return a < b * x;
	}
	void simpl() {
		ll m = __gcd(a, b);
		if (m > 1) {
			a /= m;
			b /= m;
		}
	}
	void operator+=(ll x) {
		a += x * b;
		simpl();
	}
	frac operator-(frac f) {
		return frac(a * f.b - f.a * b, b * f.b);
	}
	void operator-=(frac f) {
		*this = (*this - f);
	}
	frac operator/(ll x) {
		return frac(a, b * x);
	}
	double eval() {
		return (double)a / b;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(n);
	loop(n) {
		cin >> a[i];
	}
	vector<frac> ans(n);
	frac med(a[0]);
	for (int i = 0, j = 1, qtd = 1;i < n;) {
		if (qtd and (j == n or med < a[j] * qtd)) {
			ans[i] = med / (j - i);
			med -= ans[i];
			i++;
			qtd--;
		}
		else {
			med += a[j];
			j++;
			qtd++;
		}
	}
	each(f, ans) cout << fixed << setprecision(9) << f.eval() << endl;
	return 0;
}
