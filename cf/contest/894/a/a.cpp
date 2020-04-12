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

	string s;
	cin >> s;
	vi pos, cntl(s.length(), 0), cntr(s.length(), 0);
	int l = s.length();
	loop(l) {
		if (s[i] == 'A') pos.push_back(i);
		else if (s[i] == 'Q') cntl[i] = cntr[i] = 1;
	}
	loop(l - 1) {
		cntl[i + 1] += cntl[i];
		cntr[l - i - 2] += cntr[l - i - 1];
	}
	int ans = 0;
	each(p, pos) {
		ans += cntl[p] * cntr[p];
	}
	cout << ans << endl;
	return 0;
}

