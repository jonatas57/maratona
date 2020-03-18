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
	while (cin >> n and n) {
		int a, b, sum = 0;
		char p;
		vi v(n);
		loop(n) {
			cin >> a >> p >> b;
			v[i] = a * 100 + b;
			sum += v[i];
		}
		int x = sum / n, z = sum % n;
		int ans = 0;
		each(y, v) {
			int aux = x + (z > 0);
			if (y > aux) {
				ans += y - aux;
				y = aux;
			}
			if (y == x + 1) z--;
		}
		cout << "$" << ans / 100 << "." << setfill('0') << setw(2) << ans % 100 << endl;
	}
	return 0;
}

