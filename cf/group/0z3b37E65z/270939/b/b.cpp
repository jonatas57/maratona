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
	map<int, ii> pos;
	vector<string> t(n);
	int k, x, maxx = 0;
	loop(n) {
		cin >> t[i] >> k;
		int l = t[i].length();
		vloop(j, k) {
			cin >> x;
			maxx = max(x + l - 1, maxx);
			if (l > pos[x - 1].first) {
				pos[x - 1] = make_pair(l, i);
			}
		}
	}
	string s(maxx, 'a');
	int sl = 0;
	loop(maxx) {
		if (sl == maxx) break;
		if (pos[i].first and pos[i].first + i > sl) {
			for (int j = 0;j < pos[i].first + i - sl;j++) {
				s[sl + j] = t[pos[i].second][sl - i + j];
			}
			sl = pos[i].first + i;
		}
		else if (i >= sl) sl = i + 1;
	}

	cout << s << endl;
	return 0;
}
