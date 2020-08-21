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
		int m = INF;
		loop(n) {
			cin >> a[i];
			m = min(m, a[i]);
		}
		vi b;
		loop(n) {
			if (a[i] % m == 0) {
				b.push_back(a[i]);
			}
		}
		sort(iter(b));
		for (int i = 0, j = 0;i < n;i++) {
			if (a[i] % m == 0) {
				a[i] = b[j++];
			}
		}
		bool o = true;
		for (int i = 1;i < n;i++) {
			if (a[i] < a[i - 1]) {
				o = false;
				break;
			}
		}
		cout << (o ? "YES" : "NO") << endl;
	}
	return 0;
}

