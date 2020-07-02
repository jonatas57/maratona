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
		vi a(n), b(n);
		loop(n) cin >> a[i];
		loop(n) cin >> b[i];
		bool ans = true, ended = false;
		int del = 0;
		loop(n) {
			if (a[i] != b[i]) {
				if (!del) del = b[i] - a[i];
				else if (b[i] - a[i] != del or ended) ans = false;
			}
			else if (del) ended = true;
		}
		if (del < 0) ans = false;
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}

