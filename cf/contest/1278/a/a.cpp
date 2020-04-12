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
		string p, h;
		cin >> p >> h;
		int l = p.length();
		map<char, int> cntp, cnth;
		each(c, p) cntp[c]++;
		bool used = false, ans = false;
		for (int i = 0;i <= h.length();i++) {
			char c = h[i];
			if (cntp[c]) {
				used = true;
				cnth[c]++;
			}
			else {
				if (used) {
					bool aux = true;
					for (auto& [x, q] : cnth) {
						aux &= (q == cntp[x]);
					}
					ans = aux;
					if (!ans) cnth.clear(), used = false;
				}
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}

