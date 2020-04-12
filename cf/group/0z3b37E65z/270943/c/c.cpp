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

bool equi(string& s, string& t, int ls, int rs, int lt, int rt) {
	int l = rs - ls;
	bool equal = true;
	loop(l) {
		if (s[ls + i] != t[lt + i]) {
			equal = false;
			break;
		}
	}
	if (l & 1) return equal;
	if (equal) return true;
	int mids = avg(ls, rs), midt = avg(lt, rt);
	return (equi(s, t, ls, mids, lt, midt) and equi(s, t, mids, rs, midt, rt)) or
				 (equi(s, t, ls, mids, midt, rt) and equi(s, t, mids, rs, lt, midt));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s, t;
	cin >> s >> t;
	int l = s.length();
	cout << (equi(s, t, 0, l, 0, l) ? "YES" : "NO") << endl;
	return 0;
}

