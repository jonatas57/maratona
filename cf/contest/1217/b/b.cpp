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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	int n, x;
	loop(t) {
		cin >> n >> x;
		int fin = 0, maxd = 0;
		int a, b;
		loop(n) {
			cin >> a >> b;
			fin = max(a, fin);
			maxd = max(a - b, maxd);
		}
		x -= fin;
		int cnt = 1;
		if (x > 0) {
			if (maxd) {
				int d = x / maxd + (x % maxd != 0);
				cnt += d;
			}
			else cnt = -1;
		}
		cout << cnt << endl;
	}
	return 0;
}

