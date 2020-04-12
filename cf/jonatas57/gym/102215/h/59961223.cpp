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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

int ask(int p, int b) {
	cout << "? " << p << " " << b << endl;
	cout.flush();
	int ans;
	cin >> ans;
	return ans;
}

int main() {
	int n;
	cin >> n;
	vi zero, one, next(n);
	loop(n) next[i] = i + 1;
	int bit = 0, ans = 0;
	while (!next.empty()) {
		each(x, next) {
			if (ask(x, bit)) one.push_back(x);
			else zero.push_back(x);
		}
		if (zero.size() <= one.size()) {
			next = zero;
		}
		else {
			next = one;
			ans |= 1 << bit;
		}
		zero.clear();
		one.clear();
		bit++;
	}
	cout << "! " << ans << endl;
	return 0;
}
