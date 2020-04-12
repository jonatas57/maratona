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

void insert(vector<string>& path, string s) {
	if (s == "../") {
		path.pop_back();
	}
	else {
		if (s == "/") path.clear();
		path.push_back(s);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	string cmd;
	vector<string> path(1, "/");
	loop(n) {
		cin >> cmd;
		if (cmd == "pwd") {
			each(x, path) cout << x;
			cout << endl;
		}
		else {
			string cd;
			cin >> cd;
			string next = "";
			each(c, cd) {
				next += c;
				if (c == '/') {
					insert(path, next);
					next = "";
				}
			}
			next += '/';
			insert(path, next);
		}
	}
	return 0;
}

