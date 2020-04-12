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

bool isvowel(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	vi vs;
	int l;
	loop((l = s.length())) {
		if (isvowel(s[i])) vs.push_back(i);
	}
	int sz;
	if ((sz = vs.size())) {
		if (vs[0]) {
			cout << 0 << endl;
		}
		else {
			if (sz == 1) vs.push_back(l);
			sz = (sz - 1) / 2;
			cout << vs[sz + 1] - vs[sz] << endl;
		}
	}
	else {
		cout << 1 << endl;
	}
	return 0;
}
