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
		int n, c = 0, m = 0;
		int a, b;
		cin >> n;
		loop(n) {
			cin >> a >> b;
			int x = 0, y = 0;
			while (a) x += a % 10, a /= 10;
			while (b) y += b % 10, b /= 10;
			if (x >= y) c++;
			if (x <= y) m++;
		}
		cout << (c > m ? 0 : (c < m ? 1 : 2)) << " " << max(c, m) << endl;
	}
	return 0;
}

