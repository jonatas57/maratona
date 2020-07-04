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
		int n, m;
		cin >> n >> m;
		vector<vi> a(n, vi(m));
		bool pos = true;
		loop(n) {
			vloop(j, m) {
				int x = 2 + (i > 0 and i < n - 1) + (j > 0 and j < m - 1);
				cin >> a[i][j];
				if (a[i][j] > x) pos = false;
				else a[i][j] = x;
			}
		}
		if (pos) {
			cout << "YES" << endl;
			each(v, a) {
				each(x, v) cout << x << " ";
				cout << endl;
			}
		}
		else cout << "NO" << endl;
	}
	return 0;
}

