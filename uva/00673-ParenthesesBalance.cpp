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
	int t;
	cin >> t;
	getchar();
	loop(t) {
		string s;
		bool p = true;
		getline(cin, s);
		stack<char> q;
		each(c, s) {
			if (c == '(' or c == '[') q.push(c);
			else {
				if (!q.empty() and ((c == ')' and q.top() == '(') or (c == ']' and q.top() == '['))) q.pop();
				else {
					p = false;
					break;
				}
			}
		}
		if (!q.empty()) p = false;
		cout << (p ? "Yes" : "No") << endl;
	}
	return 0;
}

