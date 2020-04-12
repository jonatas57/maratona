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
	vi q(n - 1);
	loop(n - 1) cin >> q[i];
	int m = q[0];
	rep(1, n - 1, 1) q[i] += q[i - 1], m = max(q[i], m);
	int p1;
	vi p;
	if (m == -1) p.push_back((p1 = n));
	else p.push_back(p1 = n - m);
	each(x, q) p.push_back(x + p1);

	bool b = true;
	mii cnt;
	each(x, p) {
		cnt[x]++;
		if (cnt[x] > 1 || x > n || x <= 0) b = false;
	}

	if (b) each(x, p) cout << x << " "; else cout << -1;
	cout << endl;
	return 0;
}

