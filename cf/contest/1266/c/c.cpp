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

	int r, c;
	cin >> r >> c;
	if (r == 1 and c == 1) {
		cout << 0 << endl;
	}
	else if (r == 1 or c == 1) {
		int x = max(r, c);
		loop(x) {
			cout << i + 2 << (r == 1 ? " " : "\n");
		}
		if (r == 1) cout << endl;
	}
	else {
		vector<vi> a(r);
		loop(r) {
			a[i].resize(c, i + 1);
			vloop(j, c) {
				a[i][j] *= r + 1 + j;
			}
		}
		each(v, a) {
			each(x, v) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}

