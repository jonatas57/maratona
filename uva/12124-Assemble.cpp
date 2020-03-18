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
		int n, b;
		cin >> n >> b;
		string type, name;
		int p, q, aux = 1;
		map<string, int> conv;
		vector<vector<ii>> pqs;
		loop(n) {
			cin >> type >> name >> p >> q;
			if (!conv[type]) {
				conv[type] = aux++;
				pqs.emplace_back();
			}
			int x = conv[type] - 1;
			pqs[x].emplace_back(q, p);
		}
		each(v, pqs) {
			sort(iter(v));
			for (int i = v.size() - 2;i >= 0;i--) {
				v[i].second = min(v[i].second, v[i + 1].second);
			}
		}
		int l = 0, r = 1e9;
		while (l < r) {
			int mid = avg(l, r);
		
			int cost = 0;
			each(v, pqs) {
				auto it = lower_bound(iter(v), ii(mid, -1));
				if (it == v.end()) {
					cost = b + 1;
					break;
				}
				cost += it->second;
			}

			if (cost <= b) l = mid + 1;
			else r = mid;
		}
		cout << r - 1 << endl;
	}
	return 0;
}

