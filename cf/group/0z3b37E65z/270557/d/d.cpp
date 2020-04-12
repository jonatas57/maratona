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
	cin >> n;
	mii cnt;
	int x;
	loop(n) {
		cin >> x;
		cnt[x]++;
	}
	vi a;
	for (auto& [k, v] : cnt) a.push_back(v);
	sort(iter(a));
	map<int, vi> seq;
	each(x, a) {
		int y = 0;
		while (!(x & 1)) {
			x >>= 1;
			y++;
		}
		seq[x].push_back(y);
	}
	ll ans = 0;
	for (auto& [x, v] : seq) {
		int cnt = 1, id = 0;
		for (int i = 1;i < v.size();i++) {
			if (v[i] > v[i - 1] + 1) {
				id = i;
				cnt = 1;
			}
			else cnt++;
		}
		ll aux = 0;
		loop(cnt) {
			aux |= 1 << (v[id + cnt - 1] - id - cnt + 1);
		}/*@*/
		cerr << x << " " << aux * x << endl;/*@*/
		ans = max(ans, aux * x);
	}
	cout << ans << endl;
	return 0;
}

