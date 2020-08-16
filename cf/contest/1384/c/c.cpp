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
		string s, t;
		cin >> s >> t;
		vector<vi> cnt(20, vi(20, 0));
		loop(n) {
			if (s[i] != t[i]) {
				cnt[s[i] - 'a'][t[i] - 'a']++;
			}
		}
		int ans = 0;
		loop(20) {
			if (ans < 0) break;
			vloop(j, 20) {
				if (!cnt[i][j] or i == j) continue;
				if (i > j) {
					ans = -1;
					break;
				}
				else {
					ans++;
					cnt[i][j] = 0;
					for (int k = j + 1;k < 20;k++) {
						cnt[j][k] += cnt[i][k];
						cnt[i][k] = 0;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

