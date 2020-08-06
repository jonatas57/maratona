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

	int s, t, n;
	for (int c = 1;cin >> s >> t >> n and s | t | n;c++) {
		cout << "Case " << c << ":" << endl;
		loop(n + 1) {
			if (i) {
				vloop(k, s) {
					vloop(j, n + 1) {
						if (j) cout << string(s, '.');
						cout << string(t, '*');
					}
					cout << endl;
				}
			}
			loop(t) cout << string((n + 1) * t + n * s, '*') << endl;
		}
		cout << endl;
	}
	return 0;
}

