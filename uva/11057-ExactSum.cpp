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
	while (cin >> n) {
		vi a(n);
		loop(n) {
			cin >> a[i];
		}
		int m;
		cin >> m;
		sort(iter(a));
		int x, y;
		for (int i = 0, j = n - 1;i < j;) {
			if (a[i] + a[j] > m) {
				j--;
			}
			else if (a[i] + a[j] < m) {
				if (j != n - 1) j++;
				i++;
			}
			else x = a[i], y = a[j], i++;
		}
		cout << "Peter should buy books whose prices are " << x << " and " << y << "." << endl << endl;
	}
	return 0;
}

