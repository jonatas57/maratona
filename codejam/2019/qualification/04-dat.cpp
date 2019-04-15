#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, b, f;
		cin >> n >> b >> f;
		vi w(n - b, 0);
		int x = ceil(log2(n));
		string ans;
		while (--x >= 0) {
			string s = "";
			int l = n / (1 << x);
			loop(l) {
				s += string(1 << x, '0') + string(1 << x, '1');
			}
			s = s.substr(0, n);
			cout << s << endl;
			cout.flush();
			cin >> ans;
			if (ans == "-1") return 0;
			loop(n - b) {
				w[i] += (ans[i] - '0') * (1 << x);
			}
		}
		int last = -1;
		w.push_back(n);
		loop(n - b + 1) {
			for (int j = last + 1;j < w[i];j++) {
				cout << j << " ";
			}
			last = w[i];
		}
		cout << endl;
		cout.flush();
		int right;
		cin >> right;
		if (right == -1) return 0;
	}
	return 0;
}

