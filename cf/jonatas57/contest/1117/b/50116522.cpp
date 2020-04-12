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
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n,m, k;
	cin >> n >> m >> k;
	vi v(n);
	loop(n) {
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<int>());
	ull sum = 0;
	ull x = m / (k + 1);
	sum += v[0] * x * k + v[1] * x;
	ull y = m % (k + 1);
	sum += v[0] * y;
	cout << sum << endl;
	return 0;
}
