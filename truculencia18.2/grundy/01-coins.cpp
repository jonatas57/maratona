#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                1000001
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

vb mx;
bool mex(int n, int d) {
	if (n - d < 0) return true;
	return mx[n - d];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k, l, m;
	cin >> k >> l >> m;
	mx.resize(MAX);
	mx[0] = false;

	rep(1, 1000001, 1) {
		mx[i] = !(mex(i, 1) && mex(i, k) && mex(i, l));
	}
	int n;
	loop(m) {
		cin >> n;
		cout << (mx[n] ? "A" : "B");
	}
	cout << endl;
	return 0;
}

