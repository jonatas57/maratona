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
		vb ok(n, false);
		int oks = 0;
		loop(n) {
			cin >> a[i];
			if (a[i] == i + 1) {
				ok[i] = true;
				oks++;
			}
		}
		int cnt = 0, x = 0;
		loop(n) {
			if (!ok[i]) x++;
			else if (x) cnt++, x = 0;
		}
		if (x) cnt++;
		cout << min(2, cnt) << endl;
	}
	return 0;
}

