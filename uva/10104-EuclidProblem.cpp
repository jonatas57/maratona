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

tuple<int, int, int> eucl(int a, int b) {
	if (b == 0) return make_tuple(1, 0, a);
	int x, y, g;
	tie(x, y, g) = eucl(b, a % b);
	return make_tuple(y, x - a / b * y, g);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b;
	while (cin >> a >> b) {
		int n, m, g;
		tie(n, m, g) = eucl(a, b);
		cout << n << " " << m << " " << g << endl;
	}
	return 0;
}

