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
	string x = "RPSSRP";
	loop(t) {
		int n;
		vi v(3);
		cin >> n;
		loop(3) cin >> v[i];
		string bob;
		cin >> bob;
		string alice(bob.length(), ' ');
		int score = 0;
		loop(3) {
			vloop(j, bob.length()) {
				if (!v[i]) continue;
				if (bob[j] == x[i + 3]) {
					alice[j] = x[i];
					score++;
					v[i]--;
				}
			}
		}
		if (score >= (n + 1) / 2) {
			string s = "";
			int a = 0;
			loop(3) {
				a += v[i];
				s += string(v[i], x[i]);
			}
			for (int i = 0, j = 0;alice[i] and j < a;i++) {
				if (alice[i] == ' ') {
					alice[i] = s[j++];
				}
			}
			cout << "YES" << endl << alice << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

