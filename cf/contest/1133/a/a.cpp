#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int main() {

	int h1, m1, h2, m2;
	char c;
	cin >> h1 >> c >> m1;
	cin >> h2 >> c >> m2;
	int t1 = 60 * h1 + m1, t2 = 60 * h2 + m2;
	int t = (t1 + t2) / 2;
	h1 = t / 60;
	m1 = t % 60;
	printf("%02d:%02d\n", h1, m1);
	return 0;
}

