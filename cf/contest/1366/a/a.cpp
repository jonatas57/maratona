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
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
int a, b;

int f(int x) {
	if (b < x) return 0;
	int a2 = a - x - x;
	int y = min((b - x) / 2, a2);
	return x + y;
}

int ternary(int l, int r) {
	int x, y;
	while (r - l > 3) {
		int del = (r - l) / 3;
		x = l + del;
		y = r - del;
		int f1 = f(x);
		int f2 = f(y);
		if (f1 <= f2) l = x;
		if (f1 >= f2) r = y;
	}
	int ans = 0;
	for (int i = l;i <= r;i++) {
		ans = max(ans, f(i));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> a >> b;
		int sws = min(a, b / 2), sho = min(a / 2, b);
		cout << max({ternary(0, a / 2), sws, sho}) << endl;
	}
	return 0;
}

