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
		int n, m;
		cin >> n >> m;
		vector<vi> a(n, vi(m));
		vb cols(m, false);
		int c = m, l = n;
		loop(n) {
			bool x = false;
			vloop(j, m) {
				cin >> a[i][j];
				if (a[i][j]) {
					if (!cols[j]) cols[j] = true, c--;
					if (!x) x = true, l--;
				}
			}
		}
		int ans = min(c, l);
		cout << (ans & 1 ? "Ashish" : "Vivek") << endl;
	}
	return 0;
}

