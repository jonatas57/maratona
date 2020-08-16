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
		vi a(n, 0);
		loop(n) cin >> a[i];
		vector<string> ss(n + 1);
		ss[0] = string(50, 'b');
		for (int i = 1;i <= n;i++) {/*@*/cerr << i << " " << a[i - 1] << endl;/*@*/
			ss[i] = ss[i - 1].substr(0, a[i - 1]);
			ss[i] += string(50 - a[i - 1], ss[i - 1][a[i - 1]] == 'a' ? 'b' : 'a');
		}
		each(s, ss) cout << s << endl;
	}
	return 0;
}

