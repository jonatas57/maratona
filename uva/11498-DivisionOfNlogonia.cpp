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

	int k;
	vector<string> ans = {"NE", "NO", "SO", "SE"};
	while (cin >> k) {
		int n, m;
		cin >> n >> m;
		loop(k) {
			int a, b;
			cin >> a >> b;
			a -= n;
			b -= m;
			a *= b;
			int x = 0;
			if (a == 0) cout << "divisa" << endl;
			else {
				if (a < 0) x |= 1;
				if (b < 0) x |= 2;
				cout << ans[x] << endl;
			}
		}
	}
	return 0;
}

