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

vi a(401, 0);

bool leap(int x) {
	return x % 400 == 0 or (x % 4 == 0 and x % 100);
}

int f(int x) {
	if (x <= 400) return a[x];
	return a[400] * (x / 400) + f(x % 400);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	for (int i = 1, j = 2;i <= 400;i++) {
		a[i] = a[i - 1];
		bool l = leap(i);
		if (j == 4 or (j == 5 and !l)) a[i]++;
		if (l) j++;
		j++;
		if (j > 7) j -= 7;
	}
	int t;
	cin >> t;
	loop(t) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > 2) b++;
		if (c < 2) d--;
		cout << f(d) - f(b - 1) << endl;
	}
	return 0;
}

