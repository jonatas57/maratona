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

	vector<string> ts = {"S", "M", "L", "XL", "XXL", "XXXL"};
	vi cnt(6);
	loop(6) cin >> cnt[i];
	int n;
	string s;
	cin >> n;
	vector<tuple<int, int, int>> a;
	loop(n) {
		cin >> s;
		int p = s.find(',');
		if (p == string::npos) {
			for (int j = 0;j < 6;j++) if (s == ts[j]) {
				a.emplace_back(-1, j, i);
				break;
			}
		}
		else {
			int x = -1, y = -1;
			string s1 = s.substr(0, p);
			string s2 = s.substr(p + 1);
			for (int i = 0;i < 6 and (x == -1 or y == -1);i++) {
				if (s1 == ts[i]) x = i;
				else if (s2 == ts[i]) y = i;
			}
			a.emplace_back(x, y, i);
		}
	}
	sort(iter(a));
	bool p = true;
	vi ans(n, 0);
	for (auto& [i, j, id] : a) {
		if (i == -1 or cnt[i] == 0) {
			if (cnt[j] == 0) {
				p = false;
				break;
			}
			cnt[j]--;
			ans[id] = j;
		}
		else {
			cnt[i]--;
			ans[id] = i;
		}
	}
	if (p) {
		cout << "YES" << endl;
		each(x, ans) cout << ts[x] << endl;
	}
	else cout << "NO" << endl;
	return 0;
}

