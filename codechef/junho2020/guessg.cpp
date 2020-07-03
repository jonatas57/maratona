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

int k = 120;

char ask(int x) {
	k--;
	cout << x << endl;
	cout.flush();
	char c;
	cin >> c;
	if (c == 'E') exit(0);
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int l = 1, r = n;
	int l2 = avg(l, r), r2 = l2;
	bool lielast = false;
	while (r - l + 1 > k) {
		int x = avg(l, l2), y = avg(r2, r);
		string s = "";
		s += ask(x);
		s += ask(y);
		s += ask(y);
		s += ask(x);
		if (s[1] == s[2]) {
			if (s[1] == 'G') {
				l = y + 1;
				if (s[3] == 'L') {
					lielast = true;
				}
			}
			else {
				r = y - 1;
			}
		}
		else if (s[0] == s[3]) {
			if (s[0] == 'G') {
				l = x + 1;
			}
			else {
				r = x - 1;
			}
		}
		else if (s[0] == s[2]) {
			r2 = y + 1;
			l2 = x - 1;
		}
		else {
			l = x + 1;
			r = y - 1;
		}

		if (s == "GGLL" || lielast) {
			int x = l2 == r2 ? avg(l, r) : l2;
			if (ask(x) == 'G') {
				if (l2 == r2) l = x + 1;
				else l = r2;
			}
			else {
				if (l2 == r2) r = x - 1;
				else r = --l2;
			}
		}

		if (l2 == r2) {
			l2 = r2 = avg(l, r);
		}
		else if (r < r2) {
			r = l2;
			l2 = r2 = avg(l, r);
		}
		else if (l > l2) {
			l = r2;
			l2 = r2 = avg(l, r);
		}
		lielast = false;
	}
	for (int i = l;i <= r;i++) {
		ask(i);
	}
	return 0;
}

