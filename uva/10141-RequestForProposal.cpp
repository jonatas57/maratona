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

	int n, p;
	string x;
	for (int t = 0;cin >> n >> p and n | p;t++) {
		if (t) cout << endl;
		getline(cin, x);
		vector<string> rs(n);
		loop(n) getline(cin, rs[i]);
		vector<tuple<int, double, int, string>> ps;
		loop(p) {
			string name;
			int r;
			double d;
			getline(cin, name);
			cin >> d >> r;
			getline(cin, x);
			loop(r) {
				getline(cin, x);
			}
			ps.emplace_back(-r, d, i, name);
		}
		sort(iter(ps));
		cout << "RFP #" << t + 1 << endl << get<3>(ps[0]) << endl;
	}
	return 0;
}

