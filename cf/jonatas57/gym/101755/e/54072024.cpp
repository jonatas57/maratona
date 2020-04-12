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

	string s, t;
	cin >> s >> t;
	int first = -1, last = -1, x = s.size();
	loop(x) {
		if (s[i] != t[i]) {
			last = i;
			if (first == -1) first = i;
		}
	}
	bool p = true;
	rep(first, last + 1, 1) {
		if (s[i] != t[first + last - i]) p = false;
	}
	cout << (p ? "YES\n" : "NO\n");
	return 0;
}

