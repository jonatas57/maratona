#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i <= y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2

#define N                  1000000000
#define HN                 500000000

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	scanf("%d", &t);
	loop(t) {
		int n, m;
		scanf("%d %d", &n, &m);
		rep(n, m, 1) {
			bool p = true;
			for (int j = 2;j * j <= i && p;j++) {
				if (i % j == 0) p = false;
			}
			if (i != 1 && p) printf("%d\n", i);
		}
	}
	return 0;
}
