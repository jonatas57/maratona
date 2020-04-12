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

ii parse(string s) {
	stringstream ss;
	ss << s;
	string tr, op;
	ii ans(-32768, 32767);
	int x;
	while(ss >> tr >> op >> x) {
		if (op == ">=") ans.first = x;
		else ans.second = x;
		ss >> tr;
		if (tr != "&&") break;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);

	string s;
	vector<ii> a;
	while (getline(cin, s)) {
		ii aux = parse(s);
		if (aux.first <= aux.second) a.push_back(aux);
	}
	sort(iter(a));
	vector<ii> ans;
	int n = a.size();
	if (n) {
		ii x = a[0];
		loop(n - 1) {
			if (x.second >= a[i + 1].first - 1) {
				x.second = max(a[i + 1].second, x.second);
			}
			else {
				if (x.first <= x.second) ans.push_back(x);
				x = a[i + 1];
			}
		}
		if (x.first <= x.second) ans.push_back(x);
	}
	if (ans.size() == 0) cout << "false" << endl;
	else if (ans.size() == 1 && ans[0] == ii(-32768, 32767)) cout << "true" << endl;
	else {
		n = ans.size();
		loop(n) {
			if (i) cout << " ||\n";
			string t = (ans[i].first != -32768 ? "x >= " + to_string(ans[i].first) : "");
			string u = (ans[i].second != 32767 ? "x <= " + to_string(ans[i].second) : "");
			if (t == "" || u == "") cout << t << u;
			else cout << t << " && " << u;
		}
		cout << endl;
	}
	return 0;
}
