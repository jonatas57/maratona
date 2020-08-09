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

	int t;
	cin >> t;
	loop(t) {
		int n;
		mii cnt;
		cin >> n;
		int x;
		loop(n) {
			cin >> x;
			cnt[x]++;
		}
		vector<ii> a(iter(cnt));
		sort(iter(a), [](ii x, ii y) {
			return x.second == y.second ? x.first < y.first : x.second > y.second;
		});
		int qtd = 0;
		for (auto& [f, s] : a) if (s == a[0].second) qtd++;
		int aux = qtd * a[0].second;
		int rest = n - aux;
		int ans = qtd - 1 + rest / (a[0].second - 1);
		cout << ans << endl;
	}
	return 0;
}

