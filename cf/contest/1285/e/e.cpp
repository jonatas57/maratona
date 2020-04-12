#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
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
		int a, b;
		vector<tuple<int, int, bool, int>> sl;
		int l = INF, r = -INF;
		loop(n) {
			cin >> a >> b;
			l = min(a, l);
			r = max(b, r);
			sl.emplace_back(a, b, false, i);
			sl.emplace_back(b, a, true, i);
		}
		sort(iter(sl));
		int lastx = -INF;
		set<int> active;
		vi cnt(n, 0);
		int qtd = 0, j = 0, gs = 0;
		bool aux = false, last = false;
		for (auto& [a, b, rem, id] : sl) {
			j++;
			if (a != lastx) {
				if (!qtd) {
					gs++;
					j = 1;
				}
				else if (qtd == 1 and j != 2) {
					cnt[*active.begin()]++;
				}
			}
			if (rem) {
				qtd--;
				active.erase(id);
			}
			else {
				active.insert(id);
				qtd++;
			}
			last = rem;
			lastx = a;
			aux = false;
		}
		int ans = 0;
		each(x, cnt) ans = max(ans, x);
		cout << gs + ans << endl;
	}
	return 0;
}

