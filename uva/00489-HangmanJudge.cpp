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

	int r;
	while (cin >> r and r != -1) {
		cout << "Round " << r << endl;
		string s, g;
		cin >> s >> g;
		map<char, int> cnt;
		each(c, s) cnt[c]++;
		int l = s.length(), ans = 0, err = 0;
		each(c, g) {
			if (cnt[c]) {
				if (cnt[c] != INF) {
					ans += cnt[c];
					if (ans == l) break;
				}
			}
			else {
				err++;
				if (err == 7) break;
			}
			cnt[c] = INF;
		}
		cout << (err == 7 ? "You lose." : (ans == l ? "You win." : "You chickened out.")) << endl;
	}
	return 0;
}

