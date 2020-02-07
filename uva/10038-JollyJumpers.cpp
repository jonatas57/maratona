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

	int n;
	vector<string> ans = {"Not jolly", "Jolly"};
	while (cin >> n) {
		int x, y;
		cin >> x;
		vb used(n, false);
		int cnt = 0;
		bool jol = true;
		loop(n - 1) {
			cin >> y;
			int p = abs(x - y);
			if (p >= n or used[p]) jol = false;
			else {
				used[p] = true;
				cnt++;
			}
			x = y;
		}
		jol &= cnt == n - 1;
		cout << ans[jol] << endl;
	}
	return 0;
}

