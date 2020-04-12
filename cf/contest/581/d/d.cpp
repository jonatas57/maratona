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

void flip(ii& a) { swap(a.first, a.second); }

pair<ii, ii> comb(ii a, ii b, int w) {
	loop(2) {
		loop(2) {
			if (a.first + b.first == w and a.second == b.second) return {a, b};
			flip(b);
		}
		flip(a);
	}
	return {{0,0}, {0,0}};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vector<ii> a;
	int x, y;
	loop(3) {
		cin >> x >> y;
		if (x < y) swap(x, y);
		a.emplace_back(x, y);
	}
	sort(riter(a));
	int w = a[0].first;
	vector<string> ans;
	if (a[1].first == w and a[2].first == w) {
		loop(3) {
			string s(w, 'A' + i);
			vloop(j, a[i].second) ans.push_back(s);
		}
	}
	else {
		tie(a[1], a[2]) = comb(a[1], a[2], w);
		if (a[1].first and a[1].second + a[0].second == w) {
			loop(a[0].second) ans.emplace_back(w, 'A');
			string s = string(a[1].first, 'B') + string(a[2].first, 'C');
			loop(a[1].second) ans.push_back(s);
		}
	}
	if (ans.size()) {
		cout << w << endl;
		each(s, ans) cout << s << endl;
	}
	else cout << -1 << endl;
	return 0;
}

