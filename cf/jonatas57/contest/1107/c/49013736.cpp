#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vi dam(n);
	loop(n) {
		cin >> dam[i];
	}
	string s;
	cin >> s;
	ll total = 0;
	int x = 0, y = 0;
	vector<pair<int, int>> seg;
	rep(1, n + 1, 1) {
		if (s[i] == s[i - 1]) {
			y++;
		}
		else {
			int d = y - x + 1;
			if (d > k) { 
				seg.emplace_back(x, y);
			}
			x = y = i;
		}
	}
	int size = seg.size();
	for (int i = 0, j = 0;i < n;i++) {
		if (j >= size || i < seg[j].first) {
			total += dam[i];
		}
		else {
			vi aux(dam.begin() + seg[j].first, dam.begin() + 1 + seg[j].second);
			sort(aux.begin(), aux.end(), greater<int>());
			loop(k) {
				total += aux[i];
			}
			i = seg[j].second;
			j++;
		}
	}
	cout << total << endl;
	return 0;
}
