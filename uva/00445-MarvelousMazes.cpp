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

	vector<string> maze;
	string s;
	for (int i = 0;getline(cin, s);) {
		if (s.length()) {
			int qtd = 0;
			maze.emplace_back();
			each(c, s) {
				if (isdigit(c)) qtd += c - '0';
				else if (c == '!') {
					qtd = 0;
					maze.emplace_back();
				}
				else {
					maze.back() += string(qtd, c == 'b' ? ' ' : c);
					qtd = 0;
				}
			}
		}
		else {
			each(s, maze) cout << s << endl;
			maze.clear();
			i++;
			cout << endl;
		}
	}
	each(s, maze) cout << s << endl;
	return 0;
}

