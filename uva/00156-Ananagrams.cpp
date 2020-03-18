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

string f(string s) {
	string t = "";
	each(c, s) t += tolower(c);
	sort(iter(t));
	return t;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	vector<pair<string, string>> ws;
	while (getline(cin, s)) {
		stringstream ss;
		ss << s;
		string x;
		while (ss >> x and x != "#") {
			ws.emplace_back(f(x), x);
		}
	}
	sort(iter(ws));
	int l = ws.size();
	vector<string> ans;
	loop(l) {
		bool a = true;
		if (i and ws[i].first == ws[i - 1].first) a = false;
		if (i < l - 1 and ws[i].first == ws[i + 1].first) a = false;
		if (a) ans.push_back(ws[i].second);
	}
	sort(iter(ans));
	each(s, ans) cout << s << endl;
	return 0;
}

