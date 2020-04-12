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
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

#define PI                 3.141592653589793115997963468544l

int main() {
	int n, r;
	cin >> n >> r;
	double ang = 2 * PI / n;
	double aux = sqrt(2 - 2 * cos(ang));
	double x = (r * aux) / (2 - (aux));
	printf("%.7f\n", x);
	return 0;
}
