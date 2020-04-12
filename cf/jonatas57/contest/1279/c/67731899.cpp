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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m;
		cin >> n >> m;
		vi a(n), b(m), pos(n + 1);
		loop(n) cin >> a[i], pos[a[i]] = i;
		loop(m) cin >> b[i];
		ll last = -1, qtd = 0, ans = 0;
		each(x, b) {
			int p = pos[x];
			if (p < last) ans++, qtd--;
			else {
				qtd += p - last - 1;
				ans += 2 * qtd + 1;
				last = p;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

