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
		vector<ii> a;
		int n, x;
		cin >> n;
		loop(n) {
			cin >> x;
			a.emplace_back(x, i);
		}
		sort(iter(a));
		int l = INF, r = -1, qtd = 0;
		for (auto& [x, id] : a) {
			l = min(l, id);
			r = max(r, id);
			qtd++;
			cout << (qtd == r - l + 1);
		}
		cout << endl;
	}
	return 0;
}

