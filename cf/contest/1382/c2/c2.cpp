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

struct stri {
	string s;
	int first, last;
	bool isinv;
	stri(string s) : s(s), isinv(false) {
		first = 0;
		last = s.length() - 1;
	};
	char get(int x) { return isinv ? s[x] ^ 1 : s[x]; }
	char getFirst() { return get(first); }
	char getLast() { return get(last); }
	void removeLast() {
		if (first < last) last--;
		else last++;
	}
	void inv(int x) {
		if (x == 1) s[first] ^= 1;
		else {
			isinv = !isinv;
			swap(first, last);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		string x, t;
		cin >> n >> x >> t;
		stri s(x);
		vi ans;
		for (int i = n - 1;i >= 0;) {
			if (t[i] == s.getLast()) {
				s.removeLast();
				i--;
			}
			else {
				if (t[i] == s.getFirst()) {
					s.inv(1);
					ans.push_back(1);
				}
				s.inv(i + 1);
				ans.push_back(i + 1);
			}
		}
		cout << ans.size();
		each(x, ans) cout << " " << x;
		cout << endl;
	}
	return 0;
}

