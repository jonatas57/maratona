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

struct automat {
	string s;
	int state, size;
	automat(string s) : s(s), state(0), size(s.length()) {}
	bool next(char c) {
		if (c == s[state]) state++;
		else if (state) {
			state = 0;
			return next(c);
		}
		if (state == size) {
			state = 0;
			return true;
		}
		return false;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		string s;
		cin >> s;
		set<int> ans;
		automat one("one"), two("two");
		for (int i = 0;s[i];i++) {
			if (one.next(s[i])) ans.insert(i > 2 and s[i - 3] != 'o' ? i - 2 : i - 1);
			if (two.next(s[i])) ans.insert(s[i + 1] != 'o' ? i : i - 1);
		}
		cout << ans.size() << endl;
		each(x, ans) cout << x + 1 << " ";
		cout << endl;
	}
	return 0;
}

