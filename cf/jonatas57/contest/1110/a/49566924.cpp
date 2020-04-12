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

int main() {
	ios_base::sync_with_stdio(false);

	int b, k;
	cin >> b >> k;
	vi a(k);
	loop(k) {
		cin >> a[i];
	}
	int par = 0;
	loop(k) {
		par += (a[i] % 2) * pow(b % 2, k - i - 1);
	}
	cout << (par % 2 == 0 ? "even" : "odd") << endl;
	return 0;
}
