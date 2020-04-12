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
	vi a(n);
	loop(n) cin >> a[i];
	sort(a.begin(), a.end());
	int cnt = 1, ps = 0, last = a[0];
	auto it = a.begin();
	it++;
	for (;;it++) {
		if (it == a.end() || *it != last) {
			last = *it;
			ps += cnt / 2;
			cnt = 1;
		}
		else cnt++;
		if (it == a.end()) break;
	}
	cout << ps / 2 << endl;
	return 0;
}

