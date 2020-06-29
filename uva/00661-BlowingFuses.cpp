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

	int n, m, c;
	for (int i = 1;cin >> n >> m >> c and n | m | c;i++) {
		vi power(n);
		loop(n) cin >> power[i];
		int p = 0, maxp = 0;
		bool b = false;
		vb on(n, false);
		loop(m) {
			int x;
			cin >> x;
			x--;
			if (on[x]) {
				p -= power[x];
				on[x] = false;
			}
			else if (p + power[x] > c) {
				b = true;
			}
			else {
				p += power[x];
				on[x] = true;
				maxp = max(p, maxp);
			}
		}
		cout << "Sequence " << i << endl;
		if (b) cout << "Fuse was blown." << endl;
		else {
			cout << "Fuse was not blown.\nMaximal power consumption was " << maxp << " amperes." << endl;
		}
		cout << endl;
	}
	return 0;
}

