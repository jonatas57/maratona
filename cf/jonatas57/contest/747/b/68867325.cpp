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

	int n;
	string s;
	cin >> n >> s;
	string dna = "ACGT";
	bool p = n % 4 == 0;
	if (p) {
		int x = n / 4;
		map<char, int> cnt;
		each(c, s) {
			cnt[c]++;
			if (isupper(c) and cnt[c] > x) p = false;
		}
		if (p) {/*@*/cerr << "all < " << x << endl;
			if (cnt['?']) {
				bool ok = false;
				for (int i = 0, j = 0;s[i];i++) {
					if (isupper(s[i])) continue;
					if (!ok) {
						while (cnt[dna[j]] == x and j < 4) j++;
						if (j == 4) ok = true;
						else {
							s[i] = dna[j];
							cnt[dna[j]]++;
						}
					}
					else {
						s[i] = dna[j % 4];
						j++;
					}
				}
			}
		}
	}
	cout << (p ? s : "===") << endl;
	return 0;
}

