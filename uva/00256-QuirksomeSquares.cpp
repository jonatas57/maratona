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

int sq(int x) { return x * x; }

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	map<int, vi> memo;
	while (cin >> n) {
		vi ans = memo[n];
		if (ans.empty()) {
			int x = pow(10, n / 2);
			loop(x) {
				vloop(j, x) {
					if (sq(i + j) == i * x + j) ans.push_back(i * x + j);
				}
			}
			memo[n] = ans;
		}
		each(x, ans) cout << setfill('0') << setw(n) << x << endl;
	}
	return 0;
}

