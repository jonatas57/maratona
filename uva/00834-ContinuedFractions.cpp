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
	int n, d;
	frac(int n, int d = 1) : n(n), d(d) {
		simpl();
	}
	void simpl() {
		int m = __gcd(n, d);
		if (!m) return;
		n /= m;
		d /= m;
	}
	int intPart() {
		return n / d;
	}
	void inv() {
		swap(n, d);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b;
	while (cin >> a >> b) {
		frac f(a, b);
		vi ans;
		while (f.n) {
			ans.push_back(f.intPart());
			f.n %= f.d;
			if (f.n) f.inv();
		}
		if (ans.back() == 1) {
			ans.pop_back();
			ans.back()++;
		}
		cout << "[" << ans[0];
		if (ans.size() > 1) {
			cout << ";";
			for (int i = 1;i < ans.size();i++) {
				if (i > 1) cout << ",";
				cout << ans[i];
			}
		}
		cout << "]" << endl;
	}
	return 0;
}

