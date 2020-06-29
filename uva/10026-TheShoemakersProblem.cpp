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
	frac(int a, int b) : n(a), d(b) {
		simpl();
	}
	void simpl() {
		int m = __gcd(n, d);
		n /= m;
		d /= m;
	}
	bool operator<(const frac& f) const {
		return n * f.d > f.n * d;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		if (i) cout << endl;
		int n;
		cin >> n;
		int t, s;
		vector<pair<frac, int>> js;
		loop(n) {
			cin >> t >> s;
			js.emplace_back(frac(s, t), i + 1);
		}
		sort(iter(js));
		loop(n) {
			if (i) cout << " ";
			cout << js[i].second;
		}
		cout << endl;
	}
	return 0;
}

