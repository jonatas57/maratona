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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vi a(n);
		bool men = false, mai = true;
		vi x(1), y(1);
		cin >> x[0];
		y[0] = x[0];
		int z;
		loop(n - 1) {
			cin >> z;
			if ((z < x.back()) ^ men) {
				x.push_back(z);
				men ^= 1;
			}
			else x.back() = z;
			if ((z < y.back()) ^ mai) {
				y.push_back(z);
				mai ^= 1;
			}
			else y.back() = z;
		}
		int ansx = 0, ansy = 0;
		loop(-1 + x.size()) ansx += abs(x[i] - x[i + 1]);
		loop(-1 + y.size()) ansy += abs(y[i] - y[i + 1]);
		if (make_pair(-ansx, x.size()) < make_pair(-ansy, y.size())) {
			cout << x.size() << endl;
			each(p, x) cout << p << " ";
			cout << endl;
		}
		else {
			cout << y.size() << endl;
			each(p, y) cout << p << " ";
			cout << endl;
		}
	}
	return 0;
}

