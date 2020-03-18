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

	vi hor = {5, 0, 7, 7, 2, 7, 7, 1, 7, 7};
	vi ver = {15, 10, 6, 10, 11, 9, 13, 10, 15, 11};
	int s;
	string n;
	while (cin >> s >> n and s) {
		bool sp = false;
		vector<string> ans(5);
		each(c, n) {
			loop(5) {
				if (sp) ans[i] += " ";
				int x = i / 2;
				if (i & 1) {
					string t(s + 2, ' ');
					vloop(j, 2) {
						if (ver[c - '0'] & (1 << (j + 2 * x))) t[0 + (s + 1) * j] = '|';
					}
					ans[i] += t;
				}
				else {
					if (hor[c - '0'] & (1 << x)) ans[i] += " " + string(s, '-') + " ";
					else ans[i] += string(s + 2, ' ');
				}
			}
			sp = true;
		}
		loop(5) {
			vloop(j, (i & 1 ? s : 1)) cout << ans[i] << endl;
		}
		cout << endl;
	}
	return 0;
}

