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
	int a;
	vb e(1000001, false), used(1000001, false);
	vi ans;
	int qtd = 0, evs = 0;
	bool pos = true;
	loop(n) {
		cin >> a;
		evs++;
		if (!pos) continue;
		if (a > 0) {
			if (e[a] or used[a]) pos = false;
			else e[a] = true, used[a] = true, qtd++;
		}
		else {
			if (!e[-a]) pos = false;
			else e[-a] = false, qtd--;
		}
		if (!qtd) {
			ans.push_back(evs);
			evs = 0;
			used.assign(1000001, false);
		}
	}
	if (qtd) pos = false;
	if (pos) {
		cout << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}

