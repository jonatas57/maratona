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

typedef tuple<int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int l, h, r;
	vector<tup> sl;
	while (cin >> l >> h >> r) {
		sl.emplace_back(l, false, h);
		sl.emplace_back(r, true, h);
	}
	sort(iter(sl));
	int x;
	bool rem;
	priority_queue<int> hs;
	vi torem(10001, 0);
	mii ans;
	each(t, sl) {
		tie(x, rem, h) = t;
		bool print = true;
		if (rem) {
			torem[h]++;
			while (!hs.empty() and torem[hs.top()]) {
				torem[hs.top()]--;
				hs.pop();
			}
			if (!hs.empty() and hs.top() >= h) print = false;
		}
		else {
			if (!hs.empty() and hs.top() >= h) print = false;
			hs.push(h);
		}
		if (print) {
			ans[x] = max(ans[x], hs.empty() ? 0 : hs.top());
		}
	}
	bool aux = false;
	each(x, ans) cout << (aux ? " " : "") << x.first << " " << x.second, aux = true;
	cout << endl;
	return 0;
}

