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

struct frac {
	int num, den;
	frac(int n, int d) : num(abs(n)), den(abs(d)) {
		int m = __gcd(num, den);
		num /= m;
		den /= m;
		num *= ((n < 0) ^ (d < 0) ? -1 : 1);
	}
	bool operator<(const frac& f) const {
		return num * f.den < den * f.num;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, x, y;
	cin >> n >> x >> y;
	set<frac> s;
	loop(n) {
		int p, q;
		cin >> p >> q;
		p -= x;
		q -= y;
		s.emplace(q, p);
	}
	cout << s.size() << endl;
	return 0;
}
