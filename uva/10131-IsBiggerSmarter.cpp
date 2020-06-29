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

typedef tuple<int, int, int> tup;
vector<tup> es;

bool cmp(tup a, tup b) {
	return get<0>(a) < get<0>(b) and get<1>(a) < get<1>(b);
}

vi p;

vi recover(int st) {
	vi ans;
	for (int i = st;i != -1;i = p[i]) ans.push_back(get<2>(es[i]));
	return ans;
}

vi lis(int n) {
	vi d(n, 1);
	p.resize(n, -1);
	loop(n) {
		vloop(j, i) {
			if (cmp(es[j], es[i]) and d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				p[i] = j;
			}
		}
	}
	int sz = 0, id;
	loop(n) {
		if (sz < d[i]) {
			sz = d[i];
			id = i;
		}
	}
	return recover(id);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int iq, w;
	for (int i = 1;cin >> w >> iq;i++) es.emplace_back(-w, iq, i);
	sort(iter(es));
	vi ans = lis(es.size());
	cout << ans.size() << endl;
	each(x, ans) cout << x << endl;
	return 0;
}

