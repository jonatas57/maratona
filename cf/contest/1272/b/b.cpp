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

	int q;
	cin >> q;
	string aux = "LURD";
	loop(q) {
		string s;
		cin >> s;
		int x = 0, y = 0;
		map<char, int> cnt;
		int qtd = 0;
		each(c, s) {
			if (c == 'L') x--;
			else if (c == 'R') x++;
			else if (c == 'U') y++;
			else y--;
			cnt[c]++;
			qtd++;
		}
		if (x) {
			cnt[x < 0 ? 'L' : 'R'] -= abs(x);
			qtd -= abs(x);
		}
		if (y) {
			cnt[y < 0 ? 'D' : 'U'] -= abs(y);
			qtd -= abs(y);
		}
		if (cnt['L'] and not cnt['U']) cnt['L'] = cnt['R'] = 1, qtd = 2;
		if (cnt['U'] and not cnt['L']) cnt['U'] = cnt['D'] = 1, qtd = 2;
		cout << qtd << endl;
		each(c, aux) loop(cnt[c]) cout << c;
		cout << endl;
	}
	return 0;
}

