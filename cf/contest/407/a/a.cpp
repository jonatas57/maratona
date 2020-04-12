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
		if (n < 0 ^ d < 0) num = -num;
		simpl();
	}
	void simpl() {
		int m = __gcd(abs(num), den);
		num /= m;
		den /= m;
	}
	frac operator*(int n) { return frac(num * n, den); }
	bool isInt() { return num % den == 0; }
	int toInt() { return num / den; }
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	bool p = false;
	if (a > b) swap(a, b);
	int aa = a * a;
	frac k(b, a);
	for (int i = 1;i < a;i++) {
		int x = i, y = sqrt(aa - x * x);
		frac x1 = k * (-y), y1 = k * x;
		if (y * y + x * x == aa and x1.isInt() and y1.isInt()) {
			if (x1.toInt() == x or y1.toInt() == y) {
				x *= -1, y *= -1;
				if (x1.toInt() == x or y1.toInt() == y) continue;
			}
			cout << "YES" << endl;
			cout << 0 << " " << 0 << endl;
			cout << x << " " << y << endl;
			cout << x1.toInt() << " " << y1.toInt() << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}

