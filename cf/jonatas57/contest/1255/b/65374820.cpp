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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m;
		cin >> n >> m;
		vector<ii> fs(n);
		loop(n) {
			cin >> fs[i].first;
			fs[i].second = i + 1;
		}
		sort(iter(fs));
		fs.push_back(fs[0]);
		if (m < n or n == 2) cout << -1 << endl;
		else {
			vector<ii> ans;
			int sum = 0;
			loop(n) {
				ans.emplace_back(fs[i].second, fs[i + 1].second);
				sum += fs[i].first + fs[i + 1].first;
			}
			int x = ans.size();
			loop(m - x) {
				ans.emplace_back(fs[0].second, fs[1].second);
				sum += fs[0].first + fs[1].first;
			}
			cout << sum << endl;
			for (auto& [a, b] : ans) cout << a << " " << b << endl;
		}
	}
	return 0;
}

