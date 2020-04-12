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

	int q;
	cin >> q;
	loop(q) {
		string s, t;
		cin >> s >> t;
		map<char, int> cnt;
		map<char, bool> used;
		each(c, s) cnt[c]++;
		bool p = true, two = false;
		each(c, t) {
			if (!cnt[c]) {
				p = false;
			}
			else if (cnt[c] >= 2) {
				two = true;
			}
			used[c] = true;
		}
		each(c, s) {
			if (!used[c]) two = true;
		}
		cout << (s == t or (p and two) ? "YES" : "NO") << endl;
	}
	return 0;
}
