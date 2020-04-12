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
		int n, s, k;
		cin >> n >> s >> k;
		vi l, r;
		l.push_back(0);
		r.push_back(n + 1);
		int x;
		bool p = false;
		loop(k) {
			cin >> x;
			if (x < s) l.push_back(x);
			else if (x > s) r.push_back(x);
			else p = true;
		}
		int ans = 0;
		if (p) {
			ans = INF;
			int last = s;
			sort(riter(l));
			sort(iter(r));
			loop(l.size()) {
				if (last - l[i] > 1) {
					ans = min(ans, s - last + 1);
					break;
				}
				last = l[i];
			}
			last = s;
			loop(r.size()) {
				if (r[i] - last > 1) {
				  ans = min(ans, last - s + 1);
					break;
				}
				last = r[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

