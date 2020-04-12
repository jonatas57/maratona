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
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi odd, even;
	int x, sum = 0;
	loop(n) {
		cin >> x;
		sum += x;
		if (x & 1) odd.push_back(x);
		else even.push_back(x);
	}
	sort(odd.rbegin(), odd.rend());
	sort(even.rbegin(), even.rend());
	int o = odd.size(), e = even.size();
	if (e != o) {
		x = min(e, o);
		loop(x) sum -= (even[i] + odd[i]);
		if (x == e) sum -= odd[x];
		else sum -= even[x];
		cout << sum << endl;
	}
	else cout << 0 << endl;
	return 0;
}

