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

struct score {
	int solved;
	vi sub;
	int qtd, penalty;
	score() : solved(0), sub(10, 0), qtd(0), penalty(0) {}
	void submit(int p, int t, char res) {
		if (res == 'I') sub[p]++;
		else if (res == 'C') {
			int b = 1 << p;
			if (!(solved & b)) {
				solved |= b;
				qtd++;
				penalty += t + 20 * sub[p];
			}
		}
	}
		bool operator<(const score& s) const {
		return qtd == s.qtd ? penalty < s.penalty : qtd > s.qtd;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	loop(t) {
		if (i) cout << endl;
		map<int, score> scs;
		int c, p, t;
		char l;
		while (getline(cin, s) and s.length()) {
			stringstream ss;
			ss << s;
			ss >> c >> p >> t >> l;
			scs[c].submit(p, t, l);
		}
		vector<pair<score, int>> a;
		each(sc, scs) a.emplace_back(sc.second, sc.first);
		sort(iter(a));
		each(x, a) cout << x.second << " " << x.first.qtd << " " << x.first.penalty << endl;
	}
	return 0;
}

