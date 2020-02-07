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

vi s;
int f(int x) {
	int ans = 0;
	each(y, s) ans += abs(x - y);
	return ans;
}

int ternary(int l, int r) {
	int a, b;
	while (r - l >= 3) {
		int del = (r - l) / 3;
		a = l + del, b = r - del;
		int f1 = f(a);
		int f2 = f(b);
		if (f1 <= f2) r = b;
		if (f1 >= f2) l = a;
	}
	int ans = INF;
	for (int i = l;i <= r;i++) {
		ans = min(ans, f(i));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		s.assign(n, 0);
		loop(n) cin >> s[i];
		cout << ternary(0, 30000) << endl;
	}
	return 0;
}

