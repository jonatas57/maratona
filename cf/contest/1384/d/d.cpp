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
	vector<string> ans = {"LOSE", "DRAW", "WIN"};
	loop(t) {
		int n;
		cin >> n;
		vi a(n), b(30, 0);
		loop(n) {
			cin >> a[i];
			for (int j = 0, m = 1;j < 30;j++, m <<= 1) {
				if (a[i] & m) b[j]++;
			}
		}
		int w = 1;
		for (int i = 29, m = 1 << 29;m > 0;i--, m >>= 1) {
			if (b[i] & 1) {
				int x = b[i] / 2;
				if (x & 1) {
					w = n & 1 ? 0 : 2;
					break;
				}
				else {
					w = 2;
					break;
				}
			}
		}
		cout << ans[w] << endl;
	}
	return 0;
}

