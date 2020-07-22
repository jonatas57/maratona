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

int k;

bool check(int n, int m, int next) {
	if (n == k) return true;
	int x = (next + m - 1) % n;
	if (x >= k) return check(n - 1, m, x % (n - 1));
	else return false;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vi ans(14, -1);
	while (cin >> k and k) {
		int n = k + k;
		if (ans[k] == -1) {
			for (int i = k;ans[k] == -1;i += n) {
				for (int j = 1;j <= k;j++) {
					if (check(n, i + j, 0)) {
						ans[k] = i + j;
						break;
					}
				}
			}
		}
		cout << ans[k] << endl;
	}
	return 0;
}

