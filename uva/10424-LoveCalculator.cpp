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

int novesfora(int a) {
	if (a < 10) return a;
	int ans = 0;
	while (a) {
		ans += a % 10;
		a /= 10;
	}
	return novesfora(ans);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s, t;
	while (getline(cin, s)) {
		getline(cin, t);
		int a = 0, b = 0;
		each(c, s) if (isalpha(c)) a += tolower(c) - 'a' + 1;
		each(c, t) if (isalpha(c)) b += tolower(c) - 'a' + 1;
		a = novesfora(a);
		b = novesfora(b);
		if (a > b) swap(a, b);
		cout << fixed << setprecision(2) << 100.0 * a / b << " %" << endl;
	}
	return 0;
}

