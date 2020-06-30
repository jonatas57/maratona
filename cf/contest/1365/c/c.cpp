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
	vi posa(n), b(n);
	mii k;
	loop(n) {
		int a;
		cin >> a;
		posa[a - 1] = i;
	}
	loop(n) {
		cin >> b[i];
		int x = posa[b[i] - 1];
		if (x == i) k[0]++;
		else {
			int y = x - i;
			k[y]++;
			y += y < 0 ? n : -n;
			k[y]++;
		}
	}
	vector<ii> ans(iter(k));
	sort(iter(ans), [](ii a, ii b) {
		return a.second == b.second ? a.first > b.first : a.second > b.second;
	});
	cout << ans[0].second << endl;
	return 0;
}

