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

ll xp(ll b, int e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e >> 1);
	c *= c;
	if (e & 1) c *= b;
	return c;
}

vi totri(ll n) {
	vi ans;
	while (n) {
		ans.push_back(n % 3);
		n /= 3;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int q;
	cin >> q;
	loop(q) {
		ll n, ans = 0;
		cin >> n;
		vi s = totri(n);
		s.push_back(0);
		int last = 0;
		loop(s.size()) {
			if (s[i] == 2) last = i;
		}
		loop(s.size()) {
			if (i < last) {
				s[i] = 0;
			}
			else {
				s[i + 1] += s[i] / 3;
				s[i] %= 3;
				if (s[i] == 2) {
					s[i] = 0;
					s[i + 1]++;
				}
			}
			ans += s[i] * xp(3, i);
		}
		cout << ans << endl;
	}
	return 0;
}

