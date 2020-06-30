#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

char different(char c, char d) {
	if (c > d) swap(c, d);
	char a = 'a';
	if (c == a) a++;
	if (d == a) a++;
	return a;
}

auto mindifferent(string s, string t) {
	string ans = "";
	bool p = false;
	int eq = 0, dif = 0, last, l = s.length();
	loop(l) {
		if (s[i] == t[i]) {
			eq++;
			ans += s[i];
		}
		else {
			if (p) {
				ans += t[i];
				dif++;
			}
			else {
				ans += s[i];
				last = i;
			}
			p = !p;
		}
	}
	if (p) {
		ans[last] = different(s[last], t[last]);
	}
	return make_tuple(ans, eq, dif + (p));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	string s, t;
	cin >> s >> t;
	string ans;
	int equal, diff;
	tie(ans, equal, diff) = mindifferent(s, t);
	if (diff > k) cout << -1 << endl;
	else {
		if (diff < k) {
			int last;
			bool p = false;
			for (int i = 0;i < n && diff != k;i++) {
				if (s[i] == t[i]) {
					ans[i] = different(s[i], t[i]);
					diff++;
				}
				else {
					if (p) {
						ans[last] = different(s[last], t[last]);
						ans[i] = different(s[i], t[i]);
						diff++;
					}
					else {
						last = i;
						if (i == n - 1) {
							ans[i] = different(s[i], t[i]);
							diff++;
						}
					}
					p = !p;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
