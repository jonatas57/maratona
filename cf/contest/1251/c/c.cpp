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

string n;

void update(int& x, int m) {
	while (n[x] and ((n[x] - '0') & 1) != m) x++;
}

char choose(int& p, int& i) {
	char ans;
	if (!n[p]) {
		ans = n[i++];
		update(i, 1);
	}
	else if (!n[i]) {
		ans = n[p++];
		update(p, 0);
	}
	else {
		ans = n[i] < n[p] ? n[i++] : n[p++];
		update(i, 1);
		update(p, 0);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		int par = 0, imp = 0;
		update(par, 0), update(imp, 1);
		while (n[par] or n[imp]) {
			cout << choose(par, imp);
		}
		cout << endl;
	}
	return 0;
}
