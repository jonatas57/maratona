#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int binSearch(vi& ls, int k, int a, int b) {
	if (a == b) return a;
	int mid = avg(a, b);
	int sum = 0, cnt = 0;
	each(x, ls) {
		if (sum + x > mid) {
			cnt++;
			sum = 0;
		}
		sum += x;
	}
	if (sum) cnt++;
	if (cnt > k) return binSearch(ls, k, mid + 1, b);
	else return binSearch(ls, k, a, mid);
}

int main() {

	int k;
	string s;
	cin >> k;
	getchar();
	getline(cin, s);
	vi ls(1, 0);
	vector<string> ws;
	int minl = 0;
	int l = s.length(), j = 0;
	string aux = "";
	loop(l + 1) {
		if (s[i] != '\0') {
			ls[j]++;
			aux += s[i];
		}
		if (s[i] == ' ' || s[i] == '-' || s[i] == '\0') {
			minl = max(ls[j], minl);
			ls.push_back(0);
			j++;
			ws.push_back(aux);
			aux = "";
		}
	}
	int ans = binSearch(ls, k, minl, l);
	int i = 0, sum = 0;
	cout << ans << endl;
	return 0;
}

