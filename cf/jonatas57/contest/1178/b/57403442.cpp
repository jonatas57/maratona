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

	string s;
	cin >> s;
	bool vl = false, vr = false;
	ll cntl = 0, cntr = 0, l = s.length();
	vector<ll> left, right;
	loop(l) {
		if (s[i] == 'v') {
			if (vl) cntl++;
			vl = true;
		}
		else {
			vl = false;
			if (s[i] == 'o') {
				left.push_back(cntl);
			}
		}
		if (s[l - 1 - i] == 'v') {
			if (vr) cntr++;
			vr = true;
		}
		else {
			vr = false;
			if (s[l - 1 - i] == 'o') {
				right.push_back(cntr);
			}
		}
	}
	l = left.size();
	ll ans = 0;
	loop(l) {
		ans += left[i] * right[l - 1 - i];
	}
	cout << ans << endl;
	return 0;
}
