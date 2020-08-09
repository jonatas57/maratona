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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(1e5 + 1, 0);
	int x;
	int par = 0, qua = 0;
	loop(n) {
		cin >> x;
		a[x]++;
		if (a[x] % 4 == 0) qua++;
		if (a[x] % 2 == 0) par++;
	}
	int q;
	cin >> q;
	loop(q) {
		char c;
		cin >> c >> x;
		if (c == '+') {
			a[x]++;
			if (a[x] % 4 == 0) qua++;
			if (a[x] % 2 == 0) par++;
		}
		else {
			if (a[x] % 4 == 0) qua--;
			if (a[x] % 2 == 0) par--;
			a[x]--;
		}
		if (qua and par - 2 >= 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

