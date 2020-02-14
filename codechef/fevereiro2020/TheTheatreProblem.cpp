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

	vector<vi> perm;
	loop(4) vloop(j, 4) vloop(k, 4) vloop(l, 4) {
		if (i == j or i == k or i == l or j == k or j == l or k == l) continue;
		perm.push_back({i, j, k, l});
	}
	int t;
	ll ans = 0;
	cin >> t;
	loop(t) {
		vector<vi> cnt(4, vi(4, 0));
		int n, x;
		char f;
		cin >> n;
		loop(n) {
			cin >> f >> x;
			cnt[f - 'A'][(x / 3) - 1]++;
		}
		vi ps = {25, 50, 75, 100};
		int s = -INF;
		each(movie, perm) {
			each(time, perm) {
				each(price, perm) {
					int sum = 0;
					loop(4) {
						if (cnt[movie[i]][time[i]]) sum += ps[price[i]] * cnt[movie[i]][time[i]];
						else sum -= 100;
					}
					s = max(s, sum);
				}
			}
		}
		cout << s << endl;
		ans += s;
	}
	cout << ans << endl;
	return 0;
}

