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
	vi ps = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	loop(t) {
		int n, m = 0;
		cin >> n;
		vi a(n), color(11, -1);
		loop(n) {
			cin >> a[i];
			vloop(j, 11) {
				if (__gcd(a[i], ps[j]) > 1) {
					if (color[j] == -1) {
						m++;
						color[j] = m;
					}
					a[i] = color[j];
					break;
				}
			}
		}
		cout << m << endl;
		each(x, a) cout << x << " ";
		cout << endl;
	}
	return 0;
}

