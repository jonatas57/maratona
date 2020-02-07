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

vector<string> wave(int x) {
	vector<string> s;
	for (int i = 1;i <= x;i++) {
		s.emplace_back(i, '0' + i);
	}
	for (int i = x - 1;i > 0;i--) {
		s.emplace_back(i, '0' + i);
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t, a, f;
	bool p = false;
	cin >> t;
	loop(t) {
		cin >> a >> f;
		loop(f) {
			if (p) cout << endl;
			p = true;
			each(s, wave(a)) {
				cout << s << endl;
			}
		}
	}
	return 0;
}

