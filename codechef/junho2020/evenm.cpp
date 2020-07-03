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
		vector<vi> m(n, vi(n));
		for (int i = 0, x = 1;i < n;i++) {
			int del = i & 1 ? -1 : 1;
			int l = i & 1 ? n - 1 : 0;
			int r = i & 1 ? -1 : n;
			for (int j = l;j != r;j += del) {
				m[i][j] = x++;
			}
		}
		each(v, m) {
			each(x, v) cout << x << " ";
			cout << endl;
		}
	}
	return 0;
}

