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
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		map<char, int> cnt;
		each(c, s) cnt[c]++;
		vector<pair<int, char>> a;
		each(p, cnt) a.emplace_back(p.second, p.first);
		int qtd = a.size();
		sort(iter(a));
		vi acc(1, 0);
		each(p, a) acc.push_back(acc.back() + p.first);
		int c;
		loop(q) {
			cin >> c;
			int x = upper_bound(iter(a), make_pair(c, 'z')) - a.begin();
			int y = acc[x] + (qtd - x) * c;
			cout << n - y << endl;
		}
	}
	return 0;
}

