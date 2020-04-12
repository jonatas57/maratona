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
#define endl               "\n"

void fft(vector<complex<double>>& a, bool invert) {
	int n = a.size();
	if (n == 1) return;
	vector<complex<double>> a0(n / 2), a1(n / 2);
	for (int i = 0;2 * i < n;i++) {
		a0[i] = a[2 * i];
		a1[i] = a[2 * i + 1];
	}
	fft(a0, invert);
	fft(a1, invert);

	double ang = 2 * acos(-1) / n * (invert ? -1 : 1);
	complex<double> w(1), wn(cos(ang), sin(ang));
	for (int i = 0;i < n / 2;i++) {
		a[i] = a0[i] + w * a1[i];
		a[i + n / 2] = a0[i] - w * a1[i];
		if (invert) {
			a[i] /= 2;
			a[i + n / 2] /= 2;
		}
		w *= wn;
	}
}

vi mult(vi& a, vi& b) {
	vector<complex<double>> fa(iter(a)), fb(iter(b));
	int n = 1;
	while (n < a.size() + b.size()) n <<= 1;
	fa.resize(n, 0);
	fb.resize(n, 0);

	fft(fa, false);
	fft(fb, false);
	loop(n) {
		fa[i] *= fb[i];
	}
	fft(fa, true);
	vi ans(n);
	loop(n) {
		ans[i] = round(fa[i].real());
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vi a(n), b(m);
	loop(n) cin >> a[i];
	loop(m) cin >> b[i];
	vi p = mult(a, b);
	each(x, p) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

