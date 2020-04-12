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

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vi a(n);
		loop(n) cin >> a[i];
		bool p = true;
		if (n & 1) {
			loop(n) if (a[i] < min(i, n - i - 1)) p = false;
		}
		else {
			bool q = true, r = true;
			loop(n) if (a[i] < min(i, n - i)) q = false;
			loop(n) if (a[i] < min(i + 1, n - i - 1)) r = false;
			p = (q or r);
		}
		cout << (p ? "Yes" : "No") << endl;
	}
	return 0;
}

