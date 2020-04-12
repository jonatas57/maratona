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
		int n;
		cin >> n;
		vi a(n);
		loop(n) cin >> a[i];
		vi cnts;
		int cnt = 1, qtd = 0;
		for (int i = 1;i < n;i++) {
			if (a[i] == a[i - 1]) cnt++;
			else {
				if (i > n / 2) break;
				cnts.push_back(cnt);
				cnt = 1;
				qtd++;
			}
		}/*@*/cerr << qtd << endl;
		each(x, cnts) cerr << x << " ";cerr << endl;/*@*/
		int g = qtd ? cnts[0] : 0, s = 0, b = 0, pos;
		for (pos = 1;pos < qtd and s <= g;pos++) s += cnts[pos];
		for (;pos < qtd;pos++) b += cnts[pos];
		if (g >= b or g >= s) g = b = s = 0;
		cout << g << " " << s << " " << b << endl;
	}
	return 0;
}

